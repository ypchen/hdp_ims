<?php

/**
 *  TempoDB Client
 *  Copyright (c) 2012 TempoDB Inc. All rights reserved.
 *
 */
class Series {

    function __construct($id, $key, $name="", $tags=array(), $attributes=array()) {
        $this->id = $id;
        $this->key = $key;
        $this->name = $name;
        $this->tags = $tags;
        $this->attributes = $attributes;
    }

    static function to_json($obj) {
        $json = array(
            "id" => $obj->id,
            "key" => $obj->key,
            "name" => $obj->name,
            "tags" => $obj->tags,
            "attributes" => $obj->attributes ? $obj->attributes : (object) null
        );
        return $json;
    }

    static function from_json($json) {
        $id = isset($json["id"]) ? $json["id"] : "";
        $key = isset($json["key"]) ? $json["key"] : "";
        $name = isset($json["name"]) ? $json["name"] : "";
        $tags = isset($json["tags"]) ? $json["tags"] : array();
        $attributes = isset($json["attributes"]) ? $json["attributes"] : array();
        return new Series($id, $key, $name, $tags, $attributes);
    }
}


class DataPoint {

    function __construct($ts, $value) {
        $this->ts = $ts;
        $this->value = $value;
    }

    static function to_json($obj) {
        $json = array(
            "t" => $obj->ts->format("c"),
            "v" => $obj->value
        );
        return $json;
    }

    static function from_json($json) {
        $ts = isset($json["t"]) ? new DateTime($json["t"]) : NULL;
        $value = isset($json["v"]) ? $json["v"] : NULL;
        return new DataPoint($ts, $value);
    }
}


class DataSet {

    function __construct($series, $start, $end, $data=array(), $summary=NULL) {
        $this->series = $series;
        $this->start = $start;
        $this->end = $end;
        $this->data = $data;
        $this->summary = $summary;
    }

    static function to_json($obj) {
        $json = array(
            "series" => Series::to_json($obj->series),
            "start" => $obj->start->format("c"),
            "end" => $obj->end->format("c"),
            "data" => array_map("DataPoint::to_json", $obj->data),
            "summary" => isset($obj->$summary) ? Summary::to_json($obj->$summary) : (object) null
        );
        return $json;
    }

    static function from_json($json) {
        $series = isset($json["series"]) ? Series::from_json($json["series"]) : NULL;
        $start = isset($json["start"]) ? new DateTime($json["start"]) : NULL;
        $end = isset($json["end"]) ? new DateTime($json["end"]) : NULL;
        $data = isset($json["data"]) ? array_map("DataPoint::from_json", $json["data"]) : array();
        $summary = isset($json["summary"]) ? Summary::from_json($json["summary"]) : array();
        return new DataSet($series, $start, $end, $data, $summary);
    }
}


class Summary {
    private $data = array();

    public function __get($member) {
        if (isset($this->data[$member])) {
            return $this->data[$member];
        }
        return null;
    }

    public function __isset($member) {
        return isset($this->data[$member]);
    }

    public function __set($member, $value) {
        $this->data[$member] = $value;
    }

    function to_json() {
        return $data;
    }

    static function from_json($json) {
        $summary = new Summary();
        $data = isset($json) ? $json : array();

        foreach ($data as $key => $value) {
            $summary->__set($key, $value);
        }
        return $summary;
    }
}

class TempoDB {
    const API_HOST = "api.tempo-db.com";
    const API_PORT = 443;
    const API_VERSION = "v1";
    const VERSION = "0.3.0";

    function __construct($key, $secret, $host=self::API_HOST, $port=self::API_PORT, $secure=true) {
        $this->key = $key;
        $this->secret = $secret;
        $this->host = $host;
        $this->port = $port;
        $this->secure = $secure;
    }

    function create_series($key="") {
        $params["key"] = $key;

        $json = $this->request("/series/", "POST", $params);
        return Series::from_json($json[0]);
    }

    function get_series($options=array()) {
        $params = array();
        if (isset($options["ids"]))
            $params["id"] = $options["ids"];
        if (isset($options["keys"]))
            $params["key"] = $options["keys"];
        if (isset($options["tags"]))
            $params["tag"] = $options["tags"];
        if (isset($options["attributes"]))
            $params["attr"] = $options["attributes"];

        $json = $this->request("/series/", "GET", $params);
        $data = is_array($json[0]) ? $json[0] : array();
        return array_map("Series::from_json", $data);
    }

    function update_series($series) {
        $url = "/series/id/" . $series->id . "/";
        $json = $this->request($url, "PUT", Series::to_json($series));
        return Series::from_json($json[0]);
    }

    function read($start, $end, $options=array()) {
        $params = array(
            "start" => $start->format("c"),
            "end" => $end->format("c")
        );

        if (isset($options["interval"]))
            $params["interval"] = $options["interval"];
        if (isset($options["function"]))
            $params["function"] = $options["function"];

        if (isset($options["ids"]))
            $params["id"] = $options["ids"];
        if (isset($options["keys"]))
            $params["key"] = $options["keys"];
        if (isset($options["tags"]))
            $params["tag"] = $options["tags"];
        if (isset($options["attributes"]))
            $params["attr"] = $options["attributes"];
        if (isset($options["tz"]))
            $params["tz"] = $options["tz"];

        $url = "/data/";
        $json = $this->request($url, "GET", $params);
        $data = is_array($json[0]) ? $json[0] : array();
        return array_map("DataSet::from_json", $data);
    }

    function read_id($series_id, $start, $end, $interval=NULL, $function=NULL, $tz="") {
        $series_type = "id";
        $series_val = $series_id;
        return $this->_read($series_type, $series_val, $start, $end, $interval, $function, $tz);
    }

    function read_key($series_key, $start, $end, $interval=NULL, $function=NULL, $tz="") {
        $series_type = "key";
        $series_val = $series_key;
        return $this->_read($series_type, $series_val, $start, $end, $interval, $function, $tz);
    }

    function write_id($series_id, $data) {
        return $this->_write("id", $series_id, $data);
    }

    function write_key($series_key, $data) {
        return $this->_write("key", $series_key, $data);
    }

    function write_bulk($ts, $data) {
        // send POST request, formatting dates in ISO 8601
        $params = array(
            "t" => $ts->format("c"),
            "data" => $data
        );
        $json = $this->request("/data/", "POST", $params);
        return $json;
    }

    function increment_id($series_id, $data) {
        return $this->_increment("id", $series_id, $data);
    }

    function increment_key($series_key, $data) {
        return $this->_increment("key", $series_key, $data);
    }

    function increment_bulk($ts, $data) {
        // send POST request, formatting dates in ISO 8601
        $params = array(
            "t" => $ts->format("c"),
            "data" => $data
        );
        $json = $this->request("/increment/", "POST", $params);
        return $json;
    }

    private function _read($series_type, $series_val, $start, $end, $interval=NULL, $function=NULL, $tz="") {
        // send GET request, formatting dates in ISO 8601
        $params = array(
            "start" => $start->format("c"),
            "end" => $end->format("c"),
            "interval" => $interval,
            "function" => $function,
            "tz" => $tz
        );

        $url = "/series/" . $series_type . "/" . $series_val . "/data/";
        $json = $this->request($url, "GET", $params);
        return DataSet::from_json($json[0]);
    }

    private function _write($series_type, $series_val, $data) {
        $url = "/series/" . $series_type . "/" . $series_val . "/data/";
        $body = array_map("DataPoint::to_json", $data);
        $json = $this->request($url, "POST", $body);
        return $json;
    }

    private function _increment($series_type, $series_val, $data) {
        $url = "/series/" . $series_type . "/" . $series_val . "/increment/";
        $body = array_map("DataPoint::to_json", $data);
        $json = $this->request($url, "POST", $body);
        return $json;
    }

    private function request($target, $method="GET", $params=array()) {
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_USERPWD, $this->key . ":" . $this->secret);
        curl_setopt($ch, CURLOPT_HEADER, 0);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, $method);

        if ($this->secure) {
            curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, true);
            curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 2);
            curl_setopt($ch, CURLOPT_SSLVERSION, 3);
            curl_setopt($ch, CURLOPT_CAINFO, dirname(__FILE__) . "/cacert.pem");
        }

        $headers = array("User-Agent: " . "tempodb-php/" . self::VERSION);

        if ($method == "POST") {
            $path = $this->build_full_url($target);
            $body = json_encode($params);
            array_push($headers, "Content-Length: " . strlen($body), "Content-Type: application/json");

            curl_setopt($ch, CURLOPT_POSTFIELDS, $body);
        }
        else if ($method == "PUT") {
            $path = $this->build_full_url($target);
            $body = json_encode($params);
            array_push($headers, "Content-Length: " . strlen($body), "Content-Type: application/json");

            curl_setopt($ch, CURLOPT_POSTFIELDS, $body);
        }
        else {
            $path = $this->build_full_url($target, $params);
        }

        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
        curl_setopt($ch, CURLOPT_URL, $path);
        $response = curl_exec($ch);
        $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        curl_close($ch);

        if (($http_code / 100) != 2)
            throw new TempoDBClientException($response);

        return array(json_decode($response, true), $http_code);
    }

    private function build_full_url($target, $params=array()) {
        $port = $this->port == 80 ? "" : ":" . $this->port;
        $protocol = $this->secure ? "https://" : "http://";
        $base_full_url = $protocol . $this->host . $port;
        return $base_full_url . $this->build_url($target, $params);
    }

    private function build_url($url, $params=array()) {
        $target_path = $url;

        if (empty($params)) {
            return "/" . self::API_VERSION . $target_path;
        }
        else {
            return "/" . self::API_VERSION . $target_path . "?" . $this->urlencode($params);
        }
    }

    private function urlencode($params) {
        $p = array();
        foreach ($params as $key => $value) {
            if (is_array($value)) {
                foreach ($value as $k => $v) {
                    if (is_numeric($k)) {
                        array_push($p, rawurlencode($key) . "=" . rawurlencode($v));
                    }
                    else {
                        array_push($p, rawurlencode($key."[".$k."]")."=".rawurlencode($v));
                    }
                }
            }
            else {
                array_push($p, rawurlencode($key)."=".rawurlencode($value));
            }
        }
        return implode("&", $p);
    }
}

class TempoDBClientException extends Exception { }

?>

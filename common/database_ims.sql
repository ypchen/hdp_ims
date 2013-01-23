
-- Host: localhost    Database: ims

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+08:00";

--
-- Table structure for table `access`
--

DROP TABLE IF EXISTS `access`;
CREATE TABLE IF NOT EXISTS `access` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `status` tinyint(4) NOT NULL DEFAULT '1',
  `user_id` int(11) NOT NULL,
  `item_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `status` (`status`),
  KEY `user_id` (`user_id`),
  KEY `item_id` (`item_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Table structure for table `history_ims`
--

DROP TABLE IF EXISTS `history_ims`;
CREATE TABLE IF NOT EXISTS `history_ims` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ip` int(11) unsigned NOT NULL,
  `user_id` int(11) NOT NULL,
  `link` varchar(1024) NOT NULL,
  `query` varchar(4096) NOT NULL,
  `datetime` datetime NOT NULL,
  PRIMARY KEY (`id`),
  KEY `ip` (`ip`),
  KEY `user_id` (`user_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Table structure for table `item`
--

DROP TABLE IF EXISTS `item`;
CREATE TABLE IF NOT EXISTS `item` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `status` tinyint(4) NOT NULL DEFAULT '1',
  `description` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `status` (`status`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Table structure for table `log_ims`
--

DROP TABLE IF EXISTS `log_ims`;
CREATE TABLE IF NOT EXISTS `log_ims` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ip` int(11) unsigned NOT NULL,
  `user_id` int(11) NOT NULL,
  `datetime` datetime NOT NULL,
  `action` varchar(4096) NOT NULL,
  `action_type` tinyint(1) NOT NULL DEFAULT '0',
  `ims_tag` varchar(32) NOT NULL DEFAULT '',
  `ims_commit` varchar(64) NOT NULL DEFAULT '',
  `fw_tag` varchar(32) NOT NULL DEFAULT '',
  `fw_commit` varchar(64) NOT NULL DEFAULT '',
  `note` varchar(4096) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`),
  KEY `ip` (`ip`),
  KEY `user_id` (`user_id`),
  KEY `action_type` (`action_type`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Table structure for table `log_page`
--

DROP TABLE IF EXISTS `log_page`;
CREATE TABLE IF NOT EXISTS `log_page` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ip` int(11) unsigned NOT NULL,
  `page` varchar(1024) NOT NULL,
  `action` varchar(4096) NOT NULL,
  `datetime` datetime NOT NULL,
  PRIMARY KEY (`id`),
  KEY `ip` (`ip`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Table structure for table `log_remove`
--

DROP TABLE IF EXISTS `log_remove`;
CREATE TABLE IF NOT EXISTS `log_remove` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ip` int(11) unsigned NOT NULL,
  `action` varchar(4096) NOT NULL,
  `datetime` datetime NOT NULL,
  PRIMARY KEY (`id`),
  KEY `ip` (`ip`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Table structure for table `log_request`
--

DROP TABLE IF EXISTS `log_request`;
CREATE TABLE IF NOT EXISTS `log_request` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ip` int(11) unsigned NOT NULL,
  `datetime` datetime NOT NULL,
  PRIMARY KEY (`id`),
  KEY `ip` (`ip`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
CREATE TABLE IF NOT EXISTS `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `status` tinyint(4) NOT NULL DEFAULT '1',
  `mac` char(17) NOT NULL,
  `description` varchar(255) NOT NULL,
  `adult_lock` tinyint(4) NOT NULL DEFAULT '1',
  `adult_pass` varchar(64) NOT NULL DEFAULT '1234',
  PRIMARY KEY (`id`),
  UNIQUE KEY `mac` (`mac`),
  KEY `status` (`status`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

#!/bin/sh

echo Remove the working file if exists
rm -f ../hdp_ims_dereferenced.tar.bz2

echo Pack the directories and files
tar --dereference --exclude=".git/*" -cvjf ../hdp_ims_dereferenced.tar.bz2 * > /dev/null

echo Change to hdp_ims_dereferenced
cd ../hdp_ims_dereferenced

echo Remove everything except .git/ \(.git/ will not be deleted by rm -rf \*\)
rm -rf *

echo Unpack the directories and files
tar -xvjf ../hdp_ims_dereferenced.tar.bz2 > /dev/null

echo Remove the working file
rm -f ../hdp_ims_dereferenced.tar.bz2

echo Remove the dump files if something goes wrong \(for cygwin in Windows\)
rm -f sh.exe.stackdump

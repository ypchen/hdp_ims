#!/bin/sh

echo Remove the working file if exists
rm -f ../hdp_ims_dereferenced.tar.bz2

echo Pack the directories and files
tar --dereference --exclude=".git/*" -cvjf ../hdp_ims_dereferenced.tar.bz2 *

echo Change to hdp_ims_dereferenced
cd ../hdp_ims_dereferenced

echo Remove everything except .git/
mv .git ..
rm -rf *
mv ../.git .

echo Unpack the directories and files
tar -xvjf ../hdp_ims_dereferenced.tar.bz2

echo Remove the working file
rm -f ../hdp_ims_dereferenced.tar.bz2

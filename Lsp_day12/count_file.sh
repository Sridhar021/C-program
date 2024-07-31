#!/bin/bash

DIR="$1"

if [ ! -d "$DIR" ]
then
	echo "Error: $DIR not valid"
	exit 1
fi
file_count=$(find "$DIR" -type f | wc -l)
dir_count=$(find "$DIR" -type d | wc -l)

echo "Number of file; $file_count"
echo "Number of directories: $dir_count"



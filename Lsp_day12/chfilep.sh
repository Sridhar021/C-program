#!/bin/bash

DIR="$1"

if [ ! -d "$DIR" ]
then
	echo "Error: $DIR not valid"
	exit 1
fi

find "$DIR" -type f -exec chmod 755 {} \;
echo "Permissions changed for all files in $DIR"


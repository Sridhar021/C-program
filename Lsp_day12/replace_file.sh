#!/bin/bash

DIR="$1"
S_STRING="$2"
R_STRING="$3"

if [ ! -d "$DIR" ]
then
	echo "Error: $DIR not valid"
	exit 1
fi

find "$DIR" -type f -exec sed -i "s/$S_STRING/$R_STRING/g" {} \;
echo "Change '$S_STRING' to '$R_STRING' in all files in directory $DIR"



#!/bin/bash

DIR="$1"
OUTPUT="du_report.txt"

if [ ! -d "$DIR" ]
then
	echo "Error: $DIR not valid"
	exit 1
fi

du -sh "$DIR"/* > "$OUTPUT"
echo "Disk usage report stored in $OUTPUT"



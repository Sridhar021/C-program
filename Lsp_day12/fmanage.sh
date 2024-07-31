#!/bin/bash

list_files() {
	echo "Listing all files in directory $DIR"
	ls -l "$DIR"
}

total_files() {
	count=$(ls -l "$DIR" | grep -c ^-)
	echo "Total number of files in $DIR: $count"
}

copy_file() {
	local source="$1"
	local destination="$2"
	if [ -f "$DIR/$source" ]
	then
		cp "$DIR/$source" "$destination"
		echo "Copied file"
	else
		echo "File $source does not exist"
	fi
}
move_file() {
        local source="$1"
        local destination="$2"
        if [ -f "$DIR/$source" ]
        then
                cp "$DIR/$source" "$destination"
		echo "Moved file"
        else
                echo "File $source does not exist"
        fi
}

delete_file() {
	local file="$1"
	if [ -f "$DIR/$file" ]
	then
		rm "$DIR/$file"
	else
		echo "File $file does not exist"
	fi
}

com="$1"
DIR="$2"

if [ ! -d "$DIR" ]
then
	echo "Error $DIR is not valid"
fi

case "$com" in
	list)
		list_files
		;;
	count)
		total_files
		;;
	copy)
		copy_file "$3" "$4"
		;;
	move)
		move_file "$3" "$4"
		;;
	delete)
		delte_file "$3"
		;;
	*)
		echo "Invalid command"
		echo "Commands are list, count, copy, move, delete"
		;;
esac




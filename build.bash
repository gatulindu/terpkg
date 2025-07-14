#!/bin/bash

if [[ $1 == "--auto" ]]
then
	gcc *.c -o terp
	sudo mv terp /usr/local/bin/
else
	read -e -p "Compiler? " CC
	read -e -p "Install Dir? " DIR
	$CC *.c -o ./terp
	sudo mv terp $DIR
fi

#!/bin/bash
PROGRAM=$(basename $(dirname $(pwd)))
if [[ $1 == "debug" ]]
then
	gdb ./build/$PROGRAM
else
	./build/$PROGRAM
fi

#!/bin/bash

clear
gcc $1 -o program 2> /dev/null
if [ $? -eq 1 ] 
then
    echo "Compile error!"
else
    ./program
fi
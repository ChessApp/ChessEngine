#!/bin/sh
./chess-all < InputFile.txt > OutputFile.txt

FILE=OutputFile.txt
STRING="Checkmate!"
if [ ! -z $(grep "$STRING" "$FILE") ]; then echo "PASS"; else echo "FAIL"; fi

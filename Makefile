Base := gcc -std=c99 -Wall -g -O -o 

Current_File := ./Lezioni/L3.c

compile: 
	$(Base) ./Compiled/test $(Current_File)
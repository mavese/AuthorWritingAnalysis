#!/bin/bash

clear
clear
rm -f main
g++ -std=c++11 -o main Driver.cpp
./main data.txt

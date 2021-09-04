#!/bin/bash

code="$PWD"
opts=-g
cd ./bin/ > /dev/null
g++ $opts $code/./src/entrypoint.cpp -o sandbox.exe
cd $code > /dev/null

#!/bin/bash

g++ -Wall -Wextra -pedantic -std=c++17 -o main.out main.cpp && ./main.out

RET=$?

exit $RET
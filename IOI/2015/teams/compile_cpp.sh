#!/bin/bash

problem=teams

g++ -DEVAL -O2 -std=c++11 -o $problem -Wall -Wshadow -Wextra -Wconversion grader.cpp $problem.cpp

#!/bin/bash

problem=candies
memory=2097152  # 2GB

ulimit -v "${memory}"
"./${problem}"

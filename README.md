# Coding assessment
Implemented code for day 9 of the AoC challenge in 2021. This was part of the coding assessment for Tidalis

# How to run
Inside the root folder of the repo run:

cmake -S . -B build\
cmake --build build --config Release

## Run the unittest
cd build && ctest -C Release

## Run the actual program 
from root folder: \
build\src\Release\aoc_day_9.exe .\resources\input.txt

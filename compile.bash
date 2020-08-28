#!/bin/bash

# Compile C++ code for a problem
# For help, pass in -h or --help
# To compile a program, pass in the year followed by the problem number
# For an example, bash compile.bash 2019 J1
# To execute the compiled program, pass in -e or --exec

argString="$*" # Passed in arguments
IFS=" " read -ra args <<< "$argString" # Assign args variable from argv

inputFile="" # Input file name for later
bin="bin" # Binary output file

# If args array is empty
if [[ ${#args[@]} == 0 ]]; then
    exit 0
fi

# If -h or --help flags are passed
if [[ "${args[*]}" =~ "-h" ]]||[[ "${args[*]}" =~ "--help" ]]; then
    printf "Compile C++ code for a problem

To compile a program, pass in the year followed by the problem number
    e.g bash compile.bash 2019 J1

-h --help help for command
-e --exec execute binary file right after compiling
    "
    exit 0
fi

for file in "${args[0]}"/*; do # For each file in directory (args[0], the contest year)

    # If file matches the problem number (e.g J1) and has "cpp" in its name
    if [[ "$file" == *"${args[1]}"* ]]&&[[ "$file" == *"cpp"* ]]; then
        inputFile="$file"
        break
    fi

done

if [[ "$inputFile" == "" ]]; then # If no input file exists
    echo "Cannot file for problem ${args[*]}"
    exit 1
fi

# Compile with g++. If that doesn't work, try clang++
echo "g++ $inputFile -o $bin --std=c++11 || clang++ $inputFile -o $bin --std=c++11"
g++ "$inputFile" -o "$bin" --std=c++11 || clang++ "$inputFile" -o "$bin" --std=c++11

# If -e or --exec flags are passed
if [[ "${args[*]}" =~ "-e" ]]||[[ "${args[*]}" =~ "--exec" ]]; then
    if test -f "$bin"; then
        echo "Compiled!"
        ./"$bin"
    else
        echo "$bin does not exist"
    fi
fi

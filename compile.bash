argString="$*" # Passed in arguments
IFS=" " read -ra args <<< "$argString"

inputFile=""

for file in "${args[0]}"/*; do

    if [[ "$file" == *"${args[1]}"* ]]&&[[ "$file" == *"cpp"* ]]; then
        inputFile="$file"
        break;
    fi

done

printf "g++ $inputFile -o bin --std=c++11\n"
g++ "$inputFile" -o bin --std=c++11

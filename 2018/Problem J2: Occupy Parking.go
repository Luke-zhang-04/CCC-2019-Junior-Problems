package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

func list(str string) []rune { //equivalent to Pythons list function, returning an array of bytes
	output := make([]rune, 0)
	for _, i := range(str) {
		output = append(output, i)
	}
	return output
}

func input() string { // equivalent to pythons input() function, returns bufio scan
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        s := scanner.Text()
        return s
    }
    if err := scanner.Err(); err != nil {
        os.Exit(1)
    }
    return ""
}

func main() {
    amt := 0
    spaces, _ := strconv.Atoi(input())
    day1 := list(input())
    day2 := list(input())

    for i := 0; i < spaces; i++ {
        if day1[i] == 'C' && day2[i] == 'C' {
            amt ++
        }
    }

    fmt.Println(amt)
}

package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
    "strings"
)

var lines int

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

func intList(str string) []int { //equivalent to Pythons list(map(int, str.split(" ")))
	output := make([]int, 0)
    arr := strings.Fields(str)
    var outInt int
	for _, i := range(arr) {
        outInt, _ = strconv.Atoi(i)
		output = append(output, outInt)
	}
	return output
}

func reverse(array []int) []int {
	for i, j := 0, len(array)-1; i < j; i, j = i+1, j-1 {
		array[i], array[j] = array[j], array[i]
	}
	return array
}

func reverse2(array [][]int) [][]int {
	for i, j := 0, len(array)-1; i < j; i, j = i+1, j-1 {
		array[i], array[j] = array[j], array[i]
	}
	return array
}

func rotate(deg int, table [][]int) [][]int {
    output := make([][]int, 0)

    if deg == 180 {
        for i := 0; i < lines; i++ {
            output = append(output, reverse(table[i]))
        }
        output = reverse2(output)

    } else if deg == 90 {
        for i := 0; i < lines; i++ {
            temp := make([]int, 0)
            for x := 0; x < lines; x++ {
                temp = append(temp, table[len(table)-(x+1)][i])
            }
            output = append(output, temp)
        }

    } else if deg == 270 {
        for i := 0; i < lines; i++ {
            temp := make([]int, 0)
            for x := 0; x < lines; x++ {
                temp = append(temp, table[x][len(table[x])-(i+1)])
            }
            output = append(output, temp)
        }

    } else {return table}

    return output
}

func get_degree(table [][]int) int {
    var broken bool
    for i := 0; i < lines; i++ { //top
        if table[1][i] < table[0][i] {break}
        broken = false

        for x := 0; x < lines-1; x++ {
            if table[i][x] < table[i][x+1] {
                broken = true
                break
            }
        }
        if !broken {
            if i == lines-1 {return 270}
            continue
        }
        break
    }

    for i := 0; i < lines; i++ { //bottom
        if table[len(table)-2][i] < table[len(table)-1][i] {break}
        broken = false

        for x := 0; x < lines-1; x++ {
            if table[len(table)-(i+1)][x] > table[len(table)-(i+1)][x+1] {
                broken = true
                break
            }
        }
        if !broken {
            if i == lines-1 {return 90}
            continue
        }
        break
    }

    for i := 0; i < lines; i++ { //left
        if table[i][1] < table[i][0] {break}
        broken = false

        for x := 0; x < lines-1; x++ {
            if table[x][i] > table[x+1][i] {
                broken = true
                break
            }
        }
        if !broken {
            if i == lines-1 {return 0}
            continue
        }
        break
    }

    for i := 0; i < lines; i++ { //right
        if table[i][len(table[i])-1] < table[i][len(table[i])] {break}
        broken = false

        for x := 0; x < lines-1; x++ {
            if table[x][len(table[x])-(i+1)] < table[x+1][len(table[x+1])-(i+1)] {
                broken = true
                break
            }
        }
        if !broken {
            if i == lines-1 {return 180}
            continue
        }
        break
    }
    return 0
}

func main() {
    lines, _ = strconv.Atoi(input())
    table := make([][]int, 0)
    for i := 0; i < lines; i++ {
        table = append(table, intList(input()))
    }

    degree := get_degree(table)
    output := rotate(degree, table)
    for _, row := range output {
        fmt.Println(strings.Trim(strings.Join(strings.Fields(fmt.Sprint(row)), " "), "[]"))
    }
}

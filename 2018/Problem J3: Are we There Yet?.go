package main

import (
    "fmt"
    "bufio"
    "strings"
    "strconv"
    "os"
)

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

func insert(array []int, element, index int) []int { //inserts element into index of list
    array = append(array, 0)
    copy(array[index+1:], array[index:])
    array[index] = element
    return array
}

func indexOf(array []int, element int) int { //finds index of element in an array
    for index, i := range array {
        if i == element {
            return index
        }
    }
    return 0
}

func remove(array []int, element int) []int { //removes element from list
    element = indexOf(array, element)
    copy(array[element:], array[element+1:])
    return array[:len(array)-1]
}

func main() {
    dists := intList(input())
    dists = insert(dists, 0, 0)
    var sum int

    for i := 0; i < len(dists); i++ {
        output := make([]int, 0)
        index := indexOf(dists, 0)

        for x := 0; x < len(dists); x++ {
            if dists[x] == 0 {
                output = append(output, 0)

            } else if x < index {
                sum = 0
                for _, val := range dists[x:index] {
                    sum += val
                }  
                output = append(output, sum)

            } else {
                sum = 0
                for val := 0; val < len(dists[index:x]); val++ {
                    sum += dists[val+index+1]
                }
                output = append(output, sum)
            }
        }
        fmt.Println(strings.Trim(strings.Join(strings.Fields(fmt.Sprint(output)), " "), "[]")) //conver's array to string
        if i < len(dists)-1 {
            dists = remove(dists, 0)
            dists = insert(dists, 0, i+1)
        }
    }
}

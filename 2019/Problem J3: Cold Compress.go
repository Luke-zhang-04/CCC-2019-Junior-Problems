package main

import (
  "fmt"
  "strconv"
  "strings"
)

func output(str string) []string{
  index := 0
  var index2 int
  var portion string
  out_list := make([]string, 0, 0)
  str += " "

  for true {
    count := 0

    for i := index; i < len(str); i++ {
      if str[i] != str[index] {
        index2 = i-1
        break
      }
      count ++
    }

    if index2 - index > 0 {
      portion = str[index:index2]
    } else {
      portion = string(str[index])
      index2 ++
    } 

    out_list = append(out_list, strconv.Itoa(count), string(portion[0]))

    index += count

    if index+1 == len(str) {
      break
    }
  }
  return out_list
}

func main() {
  var n int
  lines := make([]string, 0, 0)
  fmt.Scan(&n)
  for i := 0; i < n; i++  {
    var input string
    fmt.Scan(&input)
    lines = append(lines, input)
  }
  for _, i := range lines {
    fmt.Println(strings.Join(output(i), " "))
  }
}

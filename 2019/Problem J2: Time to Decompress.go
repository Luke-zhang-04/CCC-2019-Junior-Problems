package main

import (
  "fmt"
  "strconv"
)

func main() {
  var amt int; fmt.Scan(&amt)
  var code []string

  for i := 0; i < amt; i++ {
    var vals[2] string
    fmt.Scan(&vals[0], &vals[1])
    code = append(code, vals[0], vals[1])
  }

  for i := 0; i < len(code); i += 2 {
    num, _ := strconv.Atoi(code[i])
    for x := 0; x < num-1; x++ {
      fmt.Printf(code[i+1])
    }
    fmt.Println(code[i+1])
  }
}

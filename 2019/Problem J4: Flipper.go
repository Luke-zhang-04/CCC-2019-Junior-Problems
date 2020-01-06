package main

import "fmt"

func count(array []byte, search string) int {
  count := 0
  for _, i := range string(array) {
    if string(i) == search {
      count ++
    }
  }
  return count
}

func main() {
  var input string
  grid := []int {1, 2, 3, 4}
  rule := make([]byte, 0, 0)
  fmt.Scan(&input)

  for i := 0; i < len(input); i++ {
    rule = append(rule, input[i])
  }

  if count(rule, "H") % 2 == 1 {
    grid = []int {3, 4, 1, 2}
  }
  if count(rule, "V") % 2 == 1 {
    grid = []int {grid[1], grid[0], grid[3], grid[2]}
  }

  fmt.Printf("%d %d\n", grid[0], grid[1])
  fmt.Printf("%d %d", grid[2], grid[3])
}

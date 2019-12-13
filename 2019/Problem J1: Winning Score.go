package main

import "fmt"

func score(a int, b int, c int) int {
  return 3*a+2*b+c
}

func main() {
  var aBaskets[3] int; var bBaskets[3] int
  fmt.Scan(&aBaskets[0], &aBaskets[1], &aBaskets[2])
  fmt.Scan(&bBaskets[0], &bBaskets[1], &bBaskets[2])
  aScore := score(aBaskets[0], aBaskets[1], aBaskets[2])
  bScore := score(bBaskets[0], bBaskets[1], bBaskets[2])

  if aScore == bScore{ fmt.Println("T")
  } else if aScore > bScore{ fmt.Println("A")
  } else { fmt.Println("B")}
}

#!/bin/python

from typing import Dict

sizeMap = {"L": 2, "M": 1, "S": 0}

jerseyCount = int(input())
athleteCount = int(input())
fulfilledCount = 0

jerseys: Dict[int, int] = {}

for number in range(1, jerseyCount + 1):
    jerseys[number] = sizeMap[input()]


requests = list(
    map(
        lambda details: (sizeMap[details[0]], int(details[1])),
        [input().split(" ") for _ in range(athleteCount)],
    )
)

fulfilled = 0

for size, number in requests:
    if number in jerseys:
        jerseySize = jerseys[number]

        if jerseySize >= size:
            fulfilled += 1

            del jerseys[number]


print(fulfilled)

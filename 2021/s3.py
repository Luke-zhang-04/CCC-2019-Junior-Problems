#!/bin/python3

from functools import reduce
from typing import List, Tuple


studentCount = int(input())

# Position, "frequency" (seconds / meter), distance
friends: List[Tuple[int, int, int]] = [
    tuple(map(int, input().split(" "))) for _ in range(studentCount)
]

if len(friends) == 1:
    print(friends[0][0])

    exit(0)

maxPosition = reduce(lambda old, new: old if old[0] > new[0] else new, friends)[0]
minPosition = 0


def time(testPosition: int) -> int:
    totalTime = 0

    for (position, speed, hearingDistance) in friends:
        if position + hearingDistance < testPosition:
            totalTime += (testPosition - position - hearingDistance) * speed
        elif position - hearingDistance > testPosition:
            totalTime += (position - hearingDistance - testPosition) * speed

    return totalTime


while minPosition < maxPosition:
    middle = (minPosition + maxPosition) // 2

    distance = time(middle)
    nextDistance = time(middle + 1)

    if distance < nextDistance:
        maxPosition = middle
    else:
        minPosition = middle + 1

print(time(minPosition))

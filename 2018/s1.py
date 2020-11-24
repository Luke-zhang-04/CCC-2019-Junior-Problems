#!/bin/python3

import sys
from typing import Union

villageCount = int(sys.stdin.readline(), 10)  # No of villages
villages = [
    int(sys.stdin.readline(), 10) for _ in range(villageCount)
]  # All village positions

villages.sort()  # Sort villages

smallestDistance: Union[float, None] = None  # Keep track of smallest neighbourhood
prevDistance: Union[float, None] = None  # Keep previously computed distance

for sliceIndex, val in enumerate(villages[1:-1]):
    index = sliceIndex + 1  # Get real index of villages

    if prevDistance == None:
        prevDistance = (val - villages[index - 1]) / 2

    leftDistance = prevDistance  # Distance from left of the village
    rightDistance = (villages[index + 1] - val) / 2  # Distance from right
    totalDistance = leftDistance + rightDistance  # Total neighbourhood size

    # Assign smallest distance if this distance is smaller
    if smallestDistance == None or totalDistance < smallestDistance:
        smallestDistance = totalDistance

    if smallestDistance == 1:  # Break at smallest distance
        break

    prevDistance = rightDistance  # Set prevDistance to the right distance

print(smallestDistance)

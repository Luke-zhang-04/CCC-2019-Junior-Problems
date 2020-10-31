#!/bin/python3

entryCount = int(input())  # No of observations
entries = []  # All observations
fastestSpeed = 0  # Fastest recorded speed


for _ in range(entryCount):  # For number of entries, add the entry to entries[]
    time, speed = input().split(" ")
    entries.append((int(time), int(speed)))

entries.sort()  # Sort the entries. Python will sort by first element in the tuple

# Go through each sprint time
for entry in range(0, entryCount - 1, 1):
    distance = entries[entry + 1][1] - entries[entry][1]  # Distance covered
    time = entries[entry + 1][0] - entries[entry][0]  # Delta time
    prevSpeed = abs(distance) / time  # v = d/t

    fastestSpeed = max(
        fastestSpeed, prevSpeed
    )  # If this speed is faster, add it. Othersise, use old speed

print(fastestSpeed)

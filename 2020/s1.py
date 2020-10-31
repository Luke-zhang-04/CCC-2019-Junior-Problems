#!/bin/python3

entryCount = int(input())
entries = []
fastestSpeed = 0


for entry in range(entryCount):
    (time, speed) = input().split(" ")
    entries.append((int(time), int(speed)))

entries.sort()

for entry in range(0, entryCount - 1, 1):
    distance = entries[entry + 1][1] - entries[entry][1]
    time = entries[entry + 1][0] - entries[entry][0]
    prevSpeed = abs(distance) / time

    fastestSpeed = max(fastestSpeed, prevSpeed)

print(fastestSpeed)

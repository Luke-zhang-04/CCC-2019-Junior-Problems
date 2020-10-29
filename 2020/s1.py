#!/usr/bin/env python3
entryCount = int(input())
entries = []
fastestSpeed = 0


for entry in range(entryCount):
    (time, speed) = input().split(" ")
    entries.append((int(time), int(speed)))

entries.sort()

(previousTime, previousPosition) = entries[0]
del entries[0]

for entry in entries:
    (time, pos) = entry

    speed = (abs(pos - previousPosition)) / (time - previousTime)
    (previousTime, previousPosition) = entry

    if speed > fastestSpeed:
        fastestSpeed = speed

print(fastestSpeed)

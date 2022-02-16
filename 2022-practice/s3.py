#!/bin/python

from typing import Dict, List


frequencies: Dict[int, int] = {}

for _ in range(int(input())):
    reading = int(input())

    frequencies[reading] = frequencies.setdefault(reading, 0) + 1

freq1 = freq2 = 0

for freq in frequencies.values():
    if freq > freq1:
        freq1 = freq
    elif freq > freq2:
        freq2 = freq

frequencies1: List[int] = []
frequencies2: List[int] = []

for reading, freq in frequencies.items():
    if freq == freq1:
        frequencies1.append(reading)
    elif freq == freq2:
        frequencies2.append(reading)

frequencies1.sort()
frequencies2.sort()

if len(frequencies1) > 1:
    print(abs(frequencies1[0] - frequencies1[-1]))
else:
    diff1 = abs(frequencies1[-1] - frequencies2[0])
    diff2 = abs(frequencies1[0] - frequencies2[-1])

    print(max(diff1, diff2))

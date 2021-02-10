#!/bin/python

recordings = int(input(), 10)  # Number of recordings
tides = list(map(int, input().split()))  # List of given recordings

tides.sort()  # Recordings are ordered generally

# Calculate the positions to slice
slice = (len(tides) // 2) if recordings % 2 == 0 else len(tides) // 2 + 1

low, high = (  # Low tides are on the first half, high tides on the second half
    tides[0:slice],
    tides[slice:],
)

low.reverse()  # Low tides go from greatest to least

for i in range(len(high)):  # Print each tide accordingly
    print(low[i], high[i], end=" ")

if recordings % 2 == 1:  # If an extra low tides exists at the end, print it
    print(low[-1])

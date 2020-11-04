#!/bin/python3

from typing import Tuple, List
from math import sqrt
import sys

inputCount = int(sys.stdin.readline(), 10)  # Number of inputs

inputs: List[int] = []  # All input values stored here

for _ in range(inputCount):  # Add inputs
    inputs.append(int(sys.stdin.readline(), 10))

# Largest input value to get primes from
largest = max(inputs) * 2

"""Prime number generation. SEE:
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
"""
sieve = [True] * largest
for index in range(2, int(sqrt(largest)) + 1):
    if sieve[index]:
        increment = 0
        while (index ** 2) + index * increment < largest:
            sieve[(index ** 2) + index * increment] = False
            increment += 1

# Prime numbers from 0 - the largest input
primes = [i for i in range(len(sieve)) if sieve[i] and i not in [0, 1]]


def getPair(targetVal: int) -> Tuple[int, int]:
    """Gets pair of prime numbers whose sum is of targetVal * 2
    GetPair works by using two "pointers". Since the numbers near the beginning
    and end are the most likely to add up to the target value, one pointer is
    placed at the beginning of the primes array and one is added at the end.

    The pointer near the start stays while the pointer near the end moves down.
    If the pointer values add up smaller than the target value, it either breaks
    the loop or moves the pointer forward. If it breaks, the current pointer value
    is stored for use in the next iteration.
    """
    targetVal *= 2
    pointer = len(primes) - 1  # Store previous pointer state

    for index, prime1 in enumerate(primes):  # Iterate through each prime
        while pointer >= index - 1:
            if primes[pointer] + prime1 < targetVal:
                if (
                    pointer + 1 < len(primes)
                    and primes[pointer + 1] + prime1 <= targetVal
                ):  # If the next value is also smaller or equal to the target
                    pointer += 1
                else:
                    break
            elif primes[pointer] + prime1 == targetVal:  # If its equal, return
                return primes[pointer], prime1
            else:
                pointer -= 1


pairs = tuple(map(getPair, inputs))

for pair in pairs:
    print(*pair)

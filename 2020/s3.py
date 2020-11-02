#!/bin/python3

import sys

needle = sys.stdin.readline()
haystack = sys.stdin.readline()


def getLetters(string):
    letters = {}

    for letter in string:
        letters[letter] = letters.setdefault(letter, 0) + 1

    letters.pop("\n", None)

    return letters


needleLength = len(needle)
needleLetters = getLetters(needle)
foundPermutations = set()
add = foundPermutations.add

for index in range(0, len(haystack) - needleLength + 1):
    needleSlice = haystack[index : index + needleLength - 1]

    if (
        getLetters(needleSlice) == needleLetters
        and needleSlice not in foundPermutations
    ):
        add(needleSlice)


print(len(foundPermutations))

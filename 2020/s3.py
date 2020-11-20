#!/bin/python3
# NOTE: This solution gives 7/15 points. On test 115, it times out @3.2 seconds.
# The C++ solution which uses an identical algorithm will will score 15/15

import sys

# Get needle and haystack strings
needle = sys.stdin.readline()
haystack = sys.stdin.readline()

needleLength = len(needle)  # Get needle length now so we don't call len all the time

"""Dict of letters and how many times they appear in the needle
E.g aab will be {"a": 2, "b": 1}
"""
needleLetters = {}

foundPermutations = set()  # Set of found permutations, to be hashed
prevLetters = {}  # The same as needleLetters, except for each part of the haystack
prevLetter = None  # The last letter of the previous portion of the haystack

add = foundPermutations.add  # Keep the set.add function in a variable for speed

for letter in needle:  # For each letter in needle, add it to needleLetters
    needleLetters[letter] = needleLetters.setdefault(letter, 0) + 1

# Remove the \n stat which is a side effect of sys.stdin.readline()
needleLetters.pop("\n", None)

# "Sliding window" algorithm, with a fixed window size
for index in range(0, len(haystack) - needleLength + 1):
    # Get the letters within the window
    needleSlice = haystack[index : index + needleLength - 1]

    """If no previous letter is found, perform the same loop as performed above.

    Otherwise, we can use the previous data. We can subtract 1 from the previous
    window's first letter, and add 1 to the current windows last letter. This way,
    we don't needlessly loop through needleSlice again.
    """
    if prevLetter == None:
        for letter in needleSlice:
            prevLetters[letter] = prevLetters.setdefault(letter, 0) + 1
    else:
        # Previous windows first letter
        removedLetterValue = prevLetters[prevLetter] - 1

        # If the subtracted value ends up as 0, just delete it
        if removedLetterValue == 0:
            del prevLetters[prevLetter]
        else:
            prevLetters[prevLetter] = removedLetterValue

        # Add the last letter to prevLetters
        prevLetters[needleSlice[-1]] = prevLetters.setdefault(needleSlice[-1], 0) + 1

    # Assign prevLetter to the first letter of the current window
    prevLetter = needleSlice[0]

    """We need to use a hashing algorithm, because after test 114, the strings
    become too large, and we get a memory error in the grader.

    We run hash(needleSlice) twice instead of storing a variable because storing
    it in a variable causes it to run SLOWER than if it were called twice.
    """

    # If the two dictionaries are the same, and the hashed slice isn't already found
    if prevLetters == needleLetters:
        add(hash(needleSlice))  # Use the foundPermutations.add function

print(len(foundPermutations))

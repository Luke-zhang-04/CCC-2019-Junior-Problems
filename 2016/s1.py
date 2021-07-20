#!/bin/python

from typing import Dict

string1 = input()
string2 = input()


def getLetters(string: str) -> Dict[str, int]:
    """Gets the letters of string and puts their occurences in a dictionary"""
    letters: Dict[str, int] = {}

    for letter in string:
        letters[letter] = letters.get(letter, 0) + 1

    return letters


string1Letters = getLetters(string1)
string2Letters = getLetters(string2)

for letter, string1Count in string1Letters.items():
    string2Count = string2Letters.get(letter, 0)

    letterCountDifference = string1Count - string2Count

    # If letter counts are equal
    if letterCountDifference == 0:
        string2Letters[letter] = 0
    # If string2 has more of a letter than string1, break
    elif letterCountDifference <= -1:
        print("N")

        break
    # Try to use wildcards
    else:
        wildCardCount = string2Letters.get("*", 0)

        # If wildcards available for use
        if wildCardCount >= letterCountDifference:
            string2Letters["*"] = wildCardCount - letterCountDifference
            string2Letters[letter] = 0
        else:
            print("N")

            break
else:
    print("A")

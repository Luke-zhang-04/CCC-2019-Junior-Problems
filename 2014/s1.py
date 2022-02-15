#!/bin/python

totalFriends = int(input())  # None
inputCount = int(input())

friends = [i + 1 for i in range(totalFriends)]

for _ in range(inputCount):
    multiple = int(input())
    index = 0

    while True:
        index += multiple - 1

        if index >= len(friends):
            break

        del friends[index]

for friend in friends:
    print(friend)

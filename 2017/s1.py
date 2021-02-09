#!/bin/python

gameCount = int(input(), 10)

team1 = list(map(int, input().split()))
team2 = list(map(int, input().split()))

team1Sum, team2Sum = sum(team1), sum(team2)

if team1Sum == team2Sum:  # If the sums are equal at the end, then output gameCount
    print(gameCount)
else:
    for index in range(gameCount - 1, -1, -1):  # Go through scores backwards
        team1Sum -= team1[index]  # Subtract the sum
        team2Sum -= team2[index]

        if team1Sum == team2Sum:  # If equal, output index
            print(index)

            break

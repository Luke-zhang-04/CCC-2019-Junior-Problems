#!/bin/python

problemType = int(input())

citizenCount = int(input())
speeds1 = list(map(int, input().split(" ")))
speeds2 = list(map(int, input().split(" ")))

speeds1.sort()
speeds2.sort()

if problemType == 1:
    print(
        sum(
            [
                speeds1[index] if speeds1[index] > speeds2[index] else speeds2[index]
                for index in range(citizenCount - 1, -1, -1)
            ]
        )
    )
else:
    print(
        sum(
            [
                speeds1[index]
                if speeds1[index] > speeds2[-index - 1]
                else speeds2[-index - 1]
                for index in range(citizenCount)
            ]
        )
    )

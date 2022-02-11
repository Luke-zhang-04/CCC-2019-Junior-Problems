#!/bin/python
# Very inefficient solution that still meets time limit

numbers = [int(input()) for _ in range(int(input()))]

output = []

for index in range(len(numbers)):
    number = numbers[index]

    if number == 0:
        output = output[:-1]
    else:
        output.append(number)

print(sum(output))

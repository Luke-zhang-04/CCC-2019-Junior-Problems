#!/usr/bin/env python3

rows = int(input())
columns = int(input())

squares = {}

for i in range(rows):
    vals = input().split(" ")

    for index, val in enumerate(vals):
        squares[f"{i} {index}"] = int(val)

class Node:
    children = []

    def __init__ (self, coords, val):
        self.coords = coords
        self.val = val

        x, y = coords.split(" ")
        self.multiplied = int(x) * int(y)

    def traverse (self):
        append = self.children.append
        multiplied = self.multiplied

        for square in squares:
            if (multiplied == squares[square]):
                append(Node(square, squares[square]))

        map(lambda child: child.traverse(), self.children)


#!/bin/python3

import sys
from typing import Dict

ySize, xSize = int(sys.stdin.readline(), 10), int(sys.stdin.readline(), 10)

choiceCount = int(sys.stdin.readline(), 10)

"""Rows and the number of times they should be painted over
{
    rowNumber: numberOfPaints,
}
Note that numberOfPaints should only be 0 or 1. If a row/column is painted over
twice, that's the same as never painting it, and if a row/column is over three
times, that's the same as only painting it once. Same goes for all odd and even
numbers.
"""
rows: Dict[int, int] = {}
columns: Dict[int, int] = {}

for _ in range(choiceCount):
    direction, value = sys.stdin.readline().split()

    value = int(value, 10)

    target = columns if direction == "C" else rows

    target[value] = (
        0 if target.get(value, 0) % 2 == 1 else 1
    )  # Assign target to 1 if target value is even, otherwise 0

paintedRows = tuple(  # Tuple of all the rows that have been painted "once"
    map(lambda val: val[0], filter(lambda val: val[1] == 1, rows.items()))
)
paintedColumns = tuple(  # Tuple of all the columns that have been painted "once"
    map(lambda val: val[0], filter(lambda val: val[1] == 1, columns.items()))
)

"""To calculate the number of golden squares, we add the number of pained rows
and columns together.

We know that all painted columns negate a painted row. As such, we can find the
golden squares of one row by taking the total `xSize` of the canvas, and then
subtracting the number of painted columns. Becauase the brush spans an entire
row/column, we can just multiply this one row by the number of painted rows.

We repeat that step for columns, and add the result.
"""
goldSquareCount = (len(paintedRows) * (xSize - len(paintedColumns))) + (
    len(paintedColumns) * (ySize - len(paintedRows))
)

print(goldSquareCount)

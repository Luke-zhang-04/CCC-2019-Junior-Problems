#!/bin/python

from typing import Dict
from click import BadArgumentUsage


length = int(input())

names1 = input().split(" ")
names2 = input().split(" ")


partners: Dict[str, str] = {}
"""`{name: partnerName, partnerName: name}`

Acts like a bijective map
"""

for index in range(length):
    name1, name2 = names1[index], names2[index]

    if name1 == name2:
        print("bad")
        break

    if (
        name1 in partners
        and partners[name1] != name2
        or name2 in partners
        and partners[name2] != name1
    ):
        print("bad")
        break

    partners[name1] = name2
    partners[name2] = name1
else:
    print("good")

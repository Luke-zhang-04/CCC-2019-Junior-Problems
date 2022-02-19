#!/bin/python

from typing import Dict, List, Tuple

partners: Dict[str, List[str]] = {}
separate: Dict[str, List[str]] = {}

for _ in range(int(input())):
    partner1, partner2 = input().split(" ")

    partners.setdefault(partner1, []).append(partner2)

for _ in range(int(input())):
    separate1, separate2 = input().split(" ")

    separate.setdefault(separate1, []).append(separate2)

groups: List[Tuple[str, str, str]] = [input().split(" ") for _ in range(int(input()))]


violations = 0


# Brilliant an O(n^4) algorithm or something stupid

for group in groups:
    for member in group:
        for seperate in separate.get(member, []):
            if seperate in group:
                violations += 1

        for partner in partners.get(member, []):
            if partner not in group:
                violations += 1

print(violations)

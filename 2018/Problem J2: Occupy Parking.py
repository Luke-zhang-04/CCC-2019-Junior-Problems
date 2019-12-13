amt = 0
spaces = int(input())
day1 = list(input())
day2 = list(input())

for i in range(spaces):
  amt += 1 if day1[i] == "C" and day2[i] == 'C' else 0

print(amt)

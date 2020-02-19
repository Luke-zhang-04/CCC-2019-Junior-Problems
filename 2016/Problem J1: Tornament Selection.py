wins = [input() for _ in range(6)].count("W")

if 5 <= wins <= 6: print(1)
elif 3 <= wins <= 4: print(2)
elif 1 <= wins <= 2: print(3)
else: print(-1)
def score(a, b, c):
    return 3 * a + 2 * b + c


aScore = score(int(input()), int(input()), int(input()))
bScore = score(int(input()), int(input()), int(input()))

if aScore == bScore:
    winner = "T"
elif aScore > bScore:
    winner = "A"
else:
    winner = "B"

print(winner)

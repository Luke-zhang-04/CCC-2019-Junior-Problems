code = []

for i in range(int(input())):
    code.append(input())

for i in code:
    values = i.split()
    for x in range(int(values[0]) - 1):
        print(values[1], end="")
    print(values[1])

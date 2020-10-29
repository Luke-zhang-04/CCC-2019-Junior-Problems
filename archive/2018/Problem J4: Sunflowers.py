lines = int(input())
table = []
for i in range(lines):
    table.append(list(map(int, input().split(" "))))


def rotate(deg, table):
    cout = []
    if deg == 180:
        for i in range(lines):
            cout.append(table[i][::-1])
        cout = cout[::-1]
    elif deg == 90:
        for i in range(lines):
            foo = []
            for x in range(lines):
                foo.append(table[-(x + 1)][i])
            cout.append(foo)
    elif deg == 270:
        for i in range(lines):
            foo = []
            for x in range(lines):
                foo.append(table[x][-(i + 1)])
            cout.append(foo)
    else:
        return table

    return cout


def get_degree(table):
    for i in range(lines):  # Top
        if table[1][i] < table[0][i]:
            break

        for x in range(lines - 1):
            if table[i][x] < table[i][x + 1]:
                break
        else:
            if i == lines - 1:
                return 270
            continue
        break

    for i in range(lines):  # Bottom
        if table[-2][i] < table[-1][i]:
            break

        for x in range(lines - 1):
            if table[-(i + 1)][x] > table[-(i + 1)][x + 1]:
                break
        else:
            if i == lines - 1:
                return 90
            continue
        break

    for i in range(lines):  # left
        if table[i][1] < table[i][0]:
            break

        for x in range(lines - 1):
            if table[x][i] > table[x + 1][i]:
                break
        else:
            if i == lines - 1:
                return 0
            continue
        break

    for i in range(lines):  # right
        if table[i][-2] < table[i][-1]:
            break
        for x in range(lines - 1):
            if table[x][-(i + 1)] < table[x + 1][-(i + 1)]:
                break
        else:
            if i == lines - 1:
                return 180
            continue
        break


degree = get_degree(table)
cout = rotate(degree, table)
for row in cout:
    print(*row)

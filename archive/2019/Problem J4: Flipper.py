rule = list(input())

grid = [1, 2, 3, 4]

if rule.count("H") % 2 == 1:
    grid = [3, 4, 1, 2]
if rule.count("V") % 2 == 1:
    grid = [grid[1], grid[0], grid[3], grid[2]]

print(grid[0], grid[1])
print(grid[2], grid[3])

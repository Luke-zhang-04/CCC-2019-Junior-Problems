start = list(map(int, input().split(" ")))
end = list(map(int, input().split(" ")))
charge = int(input())

distance = abs((end[1] - start[1]) + (end[0] - start[0]))

print(distance)

print("Y" if charge >= distance and (charge - distance) % 2 == 0 else "N")

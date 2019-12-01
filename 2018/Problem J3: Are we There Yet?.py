dists = list(map(int, input().split(" ")))
dists.insert(0, 0)

for i in range(len(dists)):
  cout = []
  index = dists.index(0)

  for x in range(len(dists)):
    if dists[x] == 0: cout.append(0)
    elif x < index:
      sum = 0
      for val in dists[x:index]: sum += val
      cout.append(sum)
    else:
      sum = 0
      for val in range(len(dists[index:x])): sum += dists[val+index+1]
      cout.append(sum)

  print(*cout)

  dists.remove(0)
  dists.insert(i+1, 0)

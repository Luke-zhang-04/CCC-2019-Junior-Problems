n = int(input())
lines = []

def output(string):
  index = 0
  out_list = []
  string += ' '

  while True:
    count = 0
    for i in range(index, len(string)):
      if string[i] != string[index]:
        index2 = i-1
        break
      count += 1

    if index2 - index > 0: portion = string[index:index2]
    else:
      portion = string[index]
      index2 += 1


    out_list.append(count)
    out_list.append(portion[0])
    
    index += count

    if index+1 == len(string): break

  return out_list

for i in range(n): lines.append(input())

for i in lines: print(*output(i))

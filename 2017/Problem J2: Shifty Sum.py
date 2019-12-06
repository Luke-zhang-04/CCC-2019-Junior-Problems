numb = int(input())
rep = int(input())
var = numb
total = numb

for i in range(1, rep+1):
  var *= 10
  total += var

print(total)

import math
while(True):
  n = input()
  if(n == "0"):break
  produtorio = 0
  for i in range(len(n)):
    produtorio += math.factorial(len(n)-i)*int(n[i])
  print(produtorio,end='\n')

limite = int(input())
for i in range(limite):
  string = list(input().split())
  string.sort(reverse = True,key=lambda x:len(x))
  string = " ".join(string)
  print(string,end='\n')

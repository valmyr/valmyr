d = {'0':0, '1':0, '2':0, '3':0, '4':0, '5':0, '6':0, '7':0, '8':0, '9':0}
string2int = lambda x:int(x)
while(True):
       x,y = map(string2int,input().split())
       if(x == y == 0):
              break
       while(x < y):
              for i in str(x):
                     d[str(i)]+=1
              x+=1
       for i in range(len(d)-1):
              print(f'{d[str(i)]}',end=' ')
       print(f'{d[str(i)]}',end='\n')

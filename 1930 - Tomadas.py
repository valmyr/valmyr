string2int = lambda x: int(x)
t1,t2,t3,t4 = map(string2int,input().split())
print(f'{(t1-1)+(t2-1)+(t3-1)+t4}',end='\n')

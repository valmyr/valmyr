d = {}
limite = int(input())
for i in range(limite):
              s = int(input())
              try:
                     d[s]+=1
              except KeyError:
                     d[s]=1
d = dict(sorted(d.items(),key=lambda x: x[0]))
for i in d:
       print(f'{i} aparece {d[i]} vez(es)',end='\n')


d = {}
limite = int(input())
total = 0
arvore = input()
for i in range(limite):
    total = 0
    while(True):
        try:
            arvore = input()
            if(arvore == ''):
                break
            if(arvore in d):
                d[arvore] += 1
            else:
                d[arvore] = 1
            total += 1
        except EOFError:
            break
    if(i  > 0):
        print(end='\n')
    d = dict(sorted(d.items(),key=lambda t: t[0]))
    for i in d:
        print(f'{i} {float(d[i]*100)/total:.4f}',end='\n')
    d.clear()

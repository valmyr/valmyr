escritoriosNaUltimaSemana,escritoriosNosUltimosDias = map(int,input().split())
escritorios = list(map(int,input().split()))
for i in range(escritoriosNaUltimaSemana):
    escritorio = int(input())
    if(escritorio in escritorios):
        print("0",end='')
    else:
        print("1",end='')
        escritorios.append(escritorio)
    print(end='\n')

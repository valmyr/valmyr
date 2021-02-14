escritoriosNaUltimaSemana,escritoriosNosUltimosDias = map(int,input().split())
escritorios = list(map(int,input().split()))
for i in range(escritoriosNaUltimaSemana):
    escritorio = int(input())
    if(escritorio in escritorios):
        print("0")
    else:
        print("1")
        escritorios.append(qInteiros)
    print(end='\n')

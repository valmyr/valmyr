while(True):
	limite = int(input())
	if(not(limite)):break
	campeonato = {}
	for i in range(limite):
		time,pontos = input().split()
		campeonato[time] = int(pontos)
	for i in range(limite//2):
		time1,resultado,time2 = input().split()
		resultado = resultado.replace('-','')
		campeonato[time1]+= int(resultado[0])*3
		campeonato[time2]+= int(resultado[1])*3

		if(int(resultado[0]) > int(resultado[1])):
			campeonato[time1]+=5
		elif(int(resultado[0]) < int(resultado[1])):
			campeonato[time2]+=5
		else:
			campeonato[time1]+=1
			campeonato[time2]+=1
	nomeDoTimeVencedor,pontuacaoDoTimeVencedor = [max(campeonato,key=campeonato.get),max(campeonato.values())]
	if(nomeDoTimeVencedor == "Sport"):
		print(f'O Sport foi o campeao com {pontuacaoDoTimeVencedor} pontos :D',end='\n')
	else:
		print(f'O Sport nao foi o campeao. O time campeao foi {nomeDoTimeVencedor} com {pontuacaoDoTimeVencedor} :(',end='\n')
	print(end='\n')
	campeonato.clear()

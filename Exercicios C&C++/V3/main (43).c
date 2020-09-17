lista=[1,2,3,1,2]
print("Entrada =",lista)
for i in lista:
	cont = 0
	for j in lista:
		if(i == j):
			cont+=1
	if(cont == 1):
		print("Saida =",i)
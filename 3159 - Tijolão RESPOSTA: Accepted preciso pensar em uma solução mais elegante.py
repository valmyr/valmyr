teclado = {2:"abc",3:"def",4:"ghi",5:"jkl",6:"mno",7:"pqrs",8:"tuv",9:"wxyz"}
repeticaoDeTecla = ""
limite = int(input())
for x in range(limite):
	frase = input()
	for i in range(len(frase)):
		letraMaiuscula = ""
		espaco = ""
		tempo = ""
		string = " "
		key = ""
		cont = 1
		for j in teclado:
			if(frase[i].lower() in teclado[j]):
				string = str(teclado[j])
				key = j
				break
		for k in range(len(string)):
			if(frase[i] == " "):
				espaco = "0"
			if(frase[i] == string[k].upper() and espaco != '0'):
				letraMaiuscula= '#'
			if(frase[i].lower() != string[k]):
				cont+=1
			else:
				break
		if(i == 0):
			repeticaoDeTecla = key
		elif(repeticaoDeTecla == key and letraMaiuscula != '#' and espaco != "0"):
			tempo = "*"
		else:
			repeticaoDeTecla = key
		print(letraMaiuscula,espaco,tempo,f'{key}'*cont,end='',sep='')	
	print(end='\n')

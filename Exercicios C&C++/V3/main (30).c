def impares(n1, n2):
	cont = 0
	while(n1 <= n2):
		if(n1 % 2 == 0):
			cont+=1
		n1+=1
	return cont
	
def main():
	n1 = int(input("informe n1 >> "))
	n2 = int(input("informe n2 >> "))
	print("A quantidade de numeros impares entre",n1,"e",n2,"=",impares(n1,n2))
main()
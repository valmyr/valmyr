while(1):
    nome = str(input("Informe seu sexo[F/M]: ")).strip().upper()
    if('M' == nome or nome == 'F'):
        break
print(nome)
    
while('M' != nome and  nome != 'F'):
    nome = str(input("Informe seu sexo[F/M]: ")).strip().upper()
print(nome)

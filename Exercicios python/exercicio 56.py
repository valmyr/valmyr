lista=[]
boolean = 1
midade = 0
indece = 5
cont_m = 0
for i in range (0, 4):
    nome = str(input("Informe o nome da {}ª pessoa: ".format(i+1))).strip()
    lista.append(nome)
    idade = int(input("Informe a idade da {}ª pessoa: ".format(i+1)))
    sexo = int(input("Informe o sexo M[0] F[1]: "))
    midade +=  idade
    if(sexo ==0):
        if(boolean):
            maior_idade = idade
            boolean = 0
        else:
            if(maior_idade < idade):
                indece = i
                maior_idade = idade
    if(sexo == 1 and idade < 20):
        cont_m+=1
print("A média de idade do grupo é {:.2f}".format(float(midade/4)))
if(indece == 5):
    lista.append("Não tem homens no grupo")
    print(lista[indice])
else:
    print("O homem mais velho tem {} anos e é {}".format(maior_idade,lista[indece]))
print("Existe {} mulheres com menos de 20 anos".format(cont_m))
    

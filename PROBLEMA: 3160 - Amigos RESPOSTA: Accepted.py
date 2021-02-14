atual = input().split()
nova = input().split()
indicacao = input()
if(indicacao.lower() != "nao"):
    indice = atual.index(indicacao)
    output = atual[:indice:] + nova + atual[indice:]
else:
  output = atual + nova
output = " ".join(output)
print(output,end='\n')

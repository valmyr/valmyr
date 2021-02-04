limite = int(input())
for i in range(limite):
    quantidadeDeProdutosDisponiveis = int(input())
    dicionarioComOsProdutosDisponiveisE_OsPrecos = {}
    for j in range(quantidadeDeProdutosDisponiveis):
        produto,precoPorQuilo = input().split()
        precoPorQuilo = float(precoPorQuilo)
        dicionarioComOsProdutosDisponiveisE_OsPrecos[produto] = precoPorQuilo
    quantidadeDeProdutosDiferentes = int(input())
    valorTotal_A_Pagar = 0
    for i in range(quantidadeDeProdutosDiferentes):
        produto,quantidadeDesejada = input().split()
        valorTotal_A_Pagar+=dicionarioComOsProdutosDisponiveisE_OsPrecos[produto]*float(quantidadeDesejada)
    print(f'R$ {valorTotal_A_Pagar:.2f}',end='\n')
    dicionarioComOsProdutosDisponiveisE_OsPrecos.clear()

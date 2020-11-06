# -*- coding: utf-8 -*-
# -----------------------------------------------------------------------------
# Lembre-se de que a correção será automatizada. Logo, é recomendado que, na 
# versão final do seu código (aquela que você deixará como resposta para 
# correção) você use inputs vazios, sem strings [ex: input()] e que os prints 
# na tela não façam nada mais do que o que o enunciado pede. Esteja atento para 
# não inserir pulos de linha adicionais, espaços em branco, ou qualquer outro 
# caractere não esperado. Também esteja atento com a ordem e formatos pedidos 
# nos enunciados para as entradas e saídas. Os enunciados são completos o 
# suficiente para que não fique nenhuma dúvida quanto às entradas e saídas. Os
# exemplos também são mostrados para que você perceba como seu programa deve se
# comportar como um todo (entradas,saídas e processamento). Desde a semana 4, 
# estamos alertando em vários meios (avisos, fóruns, aulas) que a falta de 
# atenção nesses aspectos pode resultar em nota zero ou notas muito baixas, 
# independente da lógica do algoritmo estar correta ou não. Não haverá revisão
# de nota para problemas causados por sua falta de atenção.
# -----------------------------------------------------------------------------
numeroDeDias = int(input())
saldoNaConta = int(input())
#menorSaldoDaConta = saldoNaConta
for i in range(0,numeroDeDias):
    dinheiroMovimentado=int(input())
    saldoNaConta+=dinheiroMovimentado
    if(not(i)):
        menorSaldoDaConta=saldoNaConta
    else:
        if(menorSaldoDaConta > saldoNaConta):
            menorSaldoDaConta = saldoNaConta
print(menorSaldoDaConta)

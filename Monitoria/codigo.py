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
'''ENUNCIADO
 

Escreva um programa em que dados P, i e n (nesta ordem, um de cada vez), calcule e mostre v (com duas casas decimais) através da fórmula abaixo:

v=p×((1+i)n)−1i

A saída do programa deve mostrar apenas o valor de v com duas casas decimais.


  

Entrada 
P, i e n (nesta ordem, um de cada vez).

 

Saída
O valor de v com duas casas decimais.

 
Exemplos'''
P = int(input())
i = float(input())
n = int(input())
print("{:.2f}".format(P*(pow(1+i,n)-1)/(i)))
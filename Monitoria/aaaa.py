n1 = float(input())
n2 = float(input())
n3 = float(input())
n4 = float(input())

while n1>n2: #lecker por n1
  if n3>n2 and n3>n4 or n4>n3: #analisando a regra em n3 e n4, já que em n2 seria inválido
    print('\nN')
  else:
    print('\nS')
  break #interromper o programa

while n2>n1 and n2>n3: #lecker por n2
  if n4>n3: #analisando a regra em n4, já que em n1 e n3 seria inválido
    print('\nN')
  else:
    print('\nS')
  break #interromper o programa

while n3>n2 and n3>n4: #lecker por n3
  if n1>n2: #analisando a regra em n1, já que em n2 ou n4 seria inválido
    break #como essa condição já foi verdadeira antes, o programa vai se interromper para não ter repetições do 'N'
  else:
    print('\nS')
  break #interromper o programa

while n4>n3: #lecker por n4
  if n1> n2 or n2>n1 and n2>n3: #analisando em n1 e n2, já que em n3 seria inválido
    break #como essa condição já foi verdadeira antes, o programa vai se interromper para não haver repetições do 'N'
  else:
    print('\nS')
  break #interromper o programa

if n1==n2 and n2==n3 and n3==n4: #condição se todos os números forem iguais
  print('\nN')

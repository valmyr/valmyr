class CarryCont:
       def __init__(self,numero_1,numero_2):
              self.numero_1 = numero_1
              self.numero_2 = numero_2
       def completandoNumeros(self):
              if(len(self.numero_1) < len(self.numero_2)):
                     self.numero_1 = self.numero_1.rjust(len(self.numero_2)+1,'0')
                     self.numero_2 = self.numero_2.rjust(len(self.numero_2)+1,'0')
                     return
              self.numero_2 = self.numero_2.rjust(len(self.numero_1)+1,'0')
              self.numero_1 = self.numero_1.rjust(len(self.numero_1)+1,'0')
              return 
       def contCarry(self):
              # 999 99 ->(9,9) = 1
              #        ->(9,9) = 1
              #        ->(
              countCarry,carry = 0,0
              if(int(self.numero_1[len(self.numero_1)-1]) + int(self.numero_2[len(self.numero_1)-1]) > 9):
                     countCarry += 1
                     carry = 1
              for i in range(len(self.numero_1)-2,0,-1):
                     if(int(self.numero_1[i]) + int(self.numero_2[i]) + carry > 9):
                            countCarry += 1
                            carry = 1
                     else:
                            carry = 0
              return countCarry
while(True):
       n1,n2 = input().split()
       if(n1 == n2 == '0'):
              break
       C = CarryCont(n1,n2)
       C.completandoNumeros()
       carry = C.contCarry()
       if(not(carry)):
              print("No carry operation.",end='\n')
       else:
              if(carry == 1):
                     print(f"{1} carry operation.",end="\n")
              else:
                     print(f"{carry} carry operations.",end="\n")
                     
'''As crianças são ensinadas a adicionar vários dígitos da direita para a esquerda, um dígito de cada vez. Muitos acham a operação "vai 1" (em inglês chamada de "carry", na qual o valor 1 é carregado de uma posição para ser adicionado ao dígito seguinte) um desafio significativo. Seu trabalho é para contar o número de operações de carry para cada um dos problemas de adição apresentados para que os educadores possam avaliar a sua dificuldade.

Entrada
Cada linha de entrada contém dois inteiros sem sinal com no máximo 9 dígitos. A última linha de entrada contém 0 0.

Saída
Para cada linha de entrada, com exceção da última, você deve computar e imprimir a quantidade de operações "leva 1" que resultam da adição dos 2 números, no formato apresentado no exemplo abaixo.'''

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
                     

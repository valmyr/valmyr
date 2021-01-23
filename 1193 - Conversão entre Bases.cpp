class MudancaDeBase:
       def __init__(self,numero,base):
              self.numero = numero
              self.base = base
       def resultado(self):
              if(self.base == "bin"):
                     print(f'{int(self.numero,2):d} dec',end='\n')
                     print(f'{int(self.numero,2):x} hex',end='\n')
              else:
                     if(self.base == 'dec'):
                            print(f'{int(self.numero):x} hex',end='\n')
                            print(f'{int(self.numero):b} bin',end='\n')
                     else:
                            print(f'{int(self.numero,16):d} dec',end='\n')
                            print(f'{int(self.numero,16):b} bin',end='\n')
n = int(input())
for i in range(n):
       numero,base = input().split()
       if(i > 0):
              print(end='\n')
       print(f"Case {i+1}:",end="\n")
       M = MudancaDeBase(numero,base)
       M.resultado()
print(end='\n')

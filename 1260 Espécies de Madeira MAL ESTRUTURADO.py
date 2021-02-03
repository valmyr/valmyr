class Arvores:
       def __init__(self,vetorDeArvores):
              self.vetorDeArvores = vetorDeArvores
              self.ocorrencia = []
              self.elementos = []
       def contarOcorrencia(self):
              sizeV = len(self.vetorDeArvores)
              for i in range(sizeV):
                     if(self.vetorDeArvores[i] in self.elementos):
                            self.ocorrencia[self.elementos.index(self.vetorDeArvores[i])]+=1
                     else:
                            self.elementos.append(self.vetorDeArvores[i])
                            self.ocorrencia.append(1)
       def sortd1(self):
              sizeOcorrencia = len(self.ocorrencia)
              flag = True
              while(flag):
                     flag = False
                     for i in range(1,sizeOcorrencia):
                            if(self.elementos[i-1] > self.elementos[i]):
                                   self.ocorrencia[i],self.ocorrencia[i-1] =  self.ocorrencia[i-1],self.ocorrencia[i]
                                   self.elementos[i],self.elementos[i-1] =  self.elementos[i-1],self.elementos[i]
                                   flag = True
                     sizeOcorrencia-=1
       def imprimir(self):
              for i in range(len(self.ocorrencia)):
                     print(f'{self.elementos[i]} {self.ocorrencia[i]*100/len(self.vetorDeArvores)}',end='\n')
              print(end='\n')
              
limite = int(input())
for i in range(limite):
       v = []
       input()
       while(True):
              try:
                     s = input()
                     v.append(s)
              except EOFError:
                     break
       s = Arvores(v)
       s.contarOcorrencia()
       s.sortd1()
       s.imprimir()

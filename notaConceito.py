def conceito(nota):
  if(nota < 3):
    return "E"
  elif(nota < 5):
    return "D"
  elif(nota < 7):
    return "C"
  elif(nota < 8):
    return "B" 
  else: 
    return "A"
print("Inserir dados? 0 - Não, 1 - Sim")
while(int(input()) == 1):
  nome = input("Nome do aluno: ")
  nota = float(input("Nota final: "))
  print(f"O aluno(a) {nome} tirou {nota} e se enquadra no conceito {conceito(nota)}")
  print("Inserir dados? 0 - Não, 1 - Sim")

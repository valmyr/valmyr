import random
aluno_1 = input("Informe o nome do primeiro aluno: ")
aluno_2 = input("Informe o nome do segundo aluno: ")
aluno_3 = input("Informe o nome do terceiro aluno: ")
aluno_4 = input("Informe o nome do quarto aluno: ")            
aluno = random.randint(1,4)
lista = [aluno_1, aluno_2, aluno_3, aluno_4]
print("O aluno escolhido foi ", f'{lista[aluno]}')

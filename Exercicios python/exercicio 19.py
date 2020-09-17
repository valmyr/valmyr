import random
aluno_1 = input("Informe o nome do primeiro aluno: ")
aluno_2 = input("Informe o nome do segundo aluno: ")
aluno_3 = input("Informe o nome do terceiro aluno: ")
aluno_4 = input("Informe o nome do quarto aluno: ")            
aluno = random.randint(1,4)
if(aluno == 1):
    print("O aluno escolhido foi", f'{aluno_1}')
else:
    if(aluno == 2):
        print("O aluno escolhido foi", f'{aluno_2}')
    else:
        if(aluno == 3):
            print("O aluno escolhido foi", f'{aluno_3}')
        else:
            print("O aluno escolhido foi", f'{aluno_4}')

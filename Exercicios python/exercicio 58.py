from random import randint
q_tentativas = 0
pc = randint(0,10)
while(1):
    chute = int(input("Informe seu palpite: "))
    if(pc == chute):
        break
    q_tentativas+=1

print("Você fez {} palpites para vencer".format(q_tentativas))

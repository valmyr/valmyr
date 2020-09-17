from datetime import datetime

ano_a = datetime.now()
ano_atual = ano_a.year

ano_ns = int(input("Informe o ano de nascimento: "))
df = ano_atual - ano_ns
if(df < 10):
    print("Até 9 anos: MIRIM")
elif(df < 15):
    print("Até 14 anos: INFANTL")
elif(df < 20):
    print("Até 19 anos: JUNIOR")
elif(df < 21):
    print("Até 20 amos: SÊNIOR")
else:
    print("Acima: MASTER")

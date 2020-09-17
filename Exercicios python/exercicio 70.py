tupla = ('zero','um','dois','três','quatro','cinco','seis','sete','oito','nove','dez','onze','doze','treze','quatorze','quinze','dezesseis','dezoito','dezenove','vinte')
while(True):
    n = int(input("Informe um número entre [0,20]: "))
    if not(0 <= n >= 20):
        break
print(tupla[n])

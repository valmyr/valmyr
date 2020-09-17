for i in range(0, 7):
    idade = int(input("Informe sua idade: "))
    if(idade >= 21):
        cont_m+=1
    else:
        cont_mm+=1
print("Maior idade", f'{cont_m}')
print("Menor idade",f'{cont_mm}')

frase = (input("Digite uma frase").upper()).strip()
print("A letra aparece", f'{frase.count("A")}', "vezes")
print("Posição ",f'{frase.find("A")}')
print("Posição ultima ",f'{frase.rfind("A")}')

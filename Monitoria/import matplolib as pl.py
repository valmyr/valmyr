import matplotlib.pyplot as plt
from random import randint
import numpy as n
h = n.empty([4],dtype = int)
for i in range (0,10):
    plt.plot([i,pow(i,2)])
    plt.show()
plt.ylabel("Numeros Y")
plt.xlabel("Numeros X")
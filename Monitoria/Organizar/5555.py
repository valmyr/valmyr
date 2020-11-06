import matplotlib.pyplot as plt
import numpy as np
m =np.empty([7],dtype = float)
n = np.empty([7],dtype = float)
x = 0
y = 70
for i in range(0,7):
    m[i]=x*0.241 + 65.6
    n[i]=x
    x+=10
print(m,n)
plt.grid(True)
plt.plot(n,m)
plt.show()

# -*- coding: utf-8 -*-
import math
#COMECE SEU CÓDIGO AQUI
F = float (input())
L = float (input())
Q = float (input())
DeltaH = float (input())
V = float (input())

g = 9.81
e= 0.000002

D = ((8 * F * L * Q**2)/(math.pi**2 * g * DeltaH)) ** (1/5)
Rey = (4 * Q)/(math.pi * D * V)
K = (0.25)/(math.log10((e/(3.7*D)) + (5.74/Rey**0.9)) **2)

print ("{:.4f}\n{:.4f}\n{:.4f}".format(D,Rey, K))

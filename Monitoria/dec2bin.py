# -*- coding: utf-8 -*-
dec = int(input())
i = 0
bin = 0
while(dec):
    bin+= (dec % 2)*pow(10,i)
    dec //=2
    i+=1
print(bin)

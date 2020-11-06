valor_saque=int(input())
a=0
a_2=0
b=0
b_2=0
c=0
c_2=0
d=0
d_2=0
e=0
e_2=0
ced20=20
ced10=10
ced5=5
ced2=2
ced1=1


if (valor_saque>=20):
   a=(valor_saque)//20
   a_2=(valor_saque)-(a*ced20) 

if (a_2 >= 10):
    b=(a_2)//10
    b_2=(valor_saque)-(b*ced10)
    
if (b_2>=5):
   c=(b_2)//5
   c_2=(valor_saque)-(c*ced5)
   
if (c_2>=2):
   d=(c_2)//5
   d_2=(valor_saque)-(d*ced2)
   
if (d_2>=1):
    e=(d_2)//1
    e_2=(valor_saque)-(e*ced1)
print(a,b,c,d,e)

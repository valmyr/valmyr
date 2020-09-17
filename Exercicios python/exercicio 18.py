from math import sin, cos, tan
ang = float(input("Informe um angulo"))
ang1 = 3.1415*ang/180
print("sen({}) = {:.2}\n cos({}) = {:.2}\ntg({}) = {:.2}\n".format(ang,sin(ang1),ang,cos(ang1),ang,tan(ang1)))

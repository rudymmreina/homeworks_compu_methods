
# coding: utf-8

# In[14]:

import numpy as np
#import matplotlib.pyplot as plt
import random
import math


# In[15]:

#masa de la luna
M_t=0.001
#masa del sol en términos a la masa de la luna
M_s=1
#definiendo alpha y beta
a=(M_s)/(M_t+M_s)
b=(M_t)/(M_t+M_s)
#distancia entre el sol y la Luna en unidades astronómicas
R=1


# In[16]:

#DEFINIENDO LAS FUNCIONES


# In[17]:

def f_3(x,y):
    return x-((b*(x-R)*(R**3))/(((x-R)**2)+(y**2))**1.5)-((a*x*(R**3))/(((x)**2)+(y**2))**1.5)


# In[18]:

def dxf_3(x,y,h):
    return (f_3(x+h,y)-f_3(x-h,y))/(2.0*h)


# In[19]:

#método de newton Raphson 


# In[20]:

x_guess = 4
y=0
h = 0.001
while (abs(f_3(x_guess,y)) > 1E-4):
    delta_x = -(f_3(x_guess,y))/(dxf_3(x_guess,y,h))
    x_guess = x_guess + delta_x
P=np.array([0,x_guess])
print "L_1 es",x_guess,P


# In[21]:

x_guess = -2
y=0
h = 0.001
while (abs(f_3(x_guess,y)) > 1E-4):
    delta_x = -(f_3(x_guess,y))/(dxf_3(x_guess,y,h))
    x_guess = x_guess + delta_x
Q=np.array([0,x_guess])
print "L_2 es",x_guess,Q


# In[22]:

print "L_3 no me sale :("


# In[23]:

f = open("puntos_lagrange.dat", "w")
f.write("x"+" "+"y"+"\n")
f.write(str(P[0])+" "+str(P[1])+"\n")
f.write(str(Q[0])+" "+str(Q[1])+"\n")
f.close()


# In[ ]:




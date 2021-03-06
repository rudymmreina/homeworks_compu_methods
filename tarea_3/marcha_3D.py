
# coding: utf-8

# In[16]:

import numpy as np
#import matplotlib.pyplot as plt
import sys
import random
import math


# In[17]:

#print random.random()


# In[18]:

#variables
#D es la distancia al que va llegar con la marcha aleatoria
#d es la longitud del vector D
#x,y,z posicion del objeto en coordenadas cartesianas
#R desplazamiento del objeto en desde el origen
#M número de marchas aleatorias
D = np.arange(10, 510, +10)
d= len(D)
M=int(sys.argv[1])

#M=10


# In[19]:

J=[]
for k in range(d):
    for l in range(M):
        r=0
        j=0
        x=0
        y=0
        z=0
        X=0
        Y=0
        Z=0
        R=0
        while(R<=D[k]):
            x = (x + 2.0*(random.random()-0.5))
            y = (y + 2.0*(random.random()-0.5))
            z = (z + 2.0*(random.random()-0.5))
            r=((x**2)+(y**2)+(z**2))**0.5
            X=x/r
            Y=y/r
            Z=Z/r
            R=R+((X**2)+(Y**2)+(Z**2))**0.5
            j=j+1
        J.append(j)


# In[20]:

#print J
Z=np.reshape(J,(d,M))
#print Z


# In[26]:

def estadistica(valores):
    suma=0
    for x in valores:
        suma+=x
       # print x
    prom=suma/float(len(valores))
    #print prom
    suma_dif_cuadrado=0
    for x in valores:
        suma_dif_cuadrado+=(prom-x)**2
        #print suma_dif_cuadrado
    varianza=suma_dif_cuadrado/float(len(valores)-1)
    return prom, math.sqrt(varianza)


# In[27]:

def promedio(valores):
    s=sum(valores)/len(valores)
    return s


# In[28]:

#print Z[0]


# In[29]:

s=estadistica(Z[0])


# In[33]:

for i in range(len(Z)):
    s=estadistica(Z[i])
    A=np.array( [D[i],s[0],s[1]])
    print A


# In[34]:

f = open("final_stats_3D_M.dat", "w")
for i in range(len(Z)):
    s=estadistica(Z[i])
    A=np.array( [D[i],s[0],s[1]])
    f.write(str(D[i])+" "+str(s[0])+" "+str(s[1])+"\n")
f.close()


# In[ ]:




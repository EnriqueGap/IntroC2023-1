import matplotlib.pyplot as plt
import pandas as pd

data1=pd.read_csv('../Math-Ficheros/input.dat',sep="\t",header=None)
data2=pd.read_csv('lagrange.dat',sep="\t",header=None)
plt.plot(data1.iloc[:,0].values,data1.iloc[:,1].values, 'o')
plt.plot(data2.iloc[:,0].values,data2.iloc[:,1].values)
plt.savefig('lagrange.png')

import matplotlib.pyplot as plt
import pandas as pd

data1=pd.read_csv('rk_yp.dat',sep="\t",header=None)
#data2=pd.read_csv('rk_ypp.dat',sep="\t",header=None)

plt.plot(data1.iloc[:,0].values,data1.iloc[:,1].values)
plt.savefig('rk_methods.png')

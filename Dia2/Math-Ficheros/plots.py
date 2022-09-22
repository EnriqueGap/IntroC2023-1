import matplotlib.pyplot as plt
import pandas as pd

data1=pd.read_csv('output.dat',sep="\t",header=None)
plt.plot(data1.iloc[:,1].values,data1.iloc[:,2].values)
plt.plot(data1.iloc[:,1].values,data1.iloc[:,3].values)
plt.savefig('output.png')

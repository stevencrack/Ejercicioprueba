import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('datosrk1.txt')
x = data[:,0]
y = data[:,1]
h = 0.1
N = 3/h

yr = np.exp(-x)

e = np.abs((yr - y)/yr)*100

plt.figure()

plt.semilogy(x, e, label='Error')

plt.savefig('error1.pdf')

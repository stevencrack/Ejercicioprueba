import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('datosrk2.txt')

x = data[:,0]

y = data[:,1]

h = 0.1

yr = np.cos(x)

e = np.abs((yr - y))*100
plt.figure()
plt.plot(x, yr)
plt.scatter(x, y)
plt.show()

plt.figure()
plt.semilogy(x, e, label='Error')
plt.legend()
plt.savefig('error2.pdf')

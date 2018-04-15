import numpy as np


# funcion para hacer la transformada de fourier en dos dimensiones

def fourier2d (x):

	M, N= x.shape
	# arreglo de ceros al cual pueden entrar numeros complejos
	trans= np.zeros([M,N], dtype =np.complex)
	
	for i in range (M):

		for j in range(N):
			h=0
			for a in range (M):
				for b in range(N):
					l=((i*a/3.0)+ (j*b/3.0))
					h+= x[a,b]*np.exp(-2j*np.pi*l)
				trans[i,j]=h
	return trans


x = np.matrix([[1,2,3],[4,5,6],[7,8,9]])

ft = fourier(x)
print ft

	

	
	

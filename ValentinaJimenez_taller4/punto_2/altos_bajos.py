import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
import sys

alto_bajo= sys.argv[2]
img = sys.argv[1]
# no piden este parametro
n_pixel_kernell=1.0

# abrir imagen
def abrir_byn(img):

	imagen= Image.open(img)
	imagenbn= imagen.convert("L")
	imagenbn.save("blancoynegro.png")
	array = plt.imread("blancoynegro.png")
	return array

a= abrir_byn(img)
print "La matriz de la imagen es: ", a

# dimensiones de la imagen, variables globales

M= (np.shape(a)[0])
N= (np.shape(a)[1])

def fourier2d (x):

	global M
	global n
	M=(np.shape(x)[0])
	N=(np.shape(x)[1])
	# arreglo de ceros al cual pueden entrar numeros complejos
	trans= np.zeros((M,N), dtype=complex)
	
	for i in range (M):
		for j in range(N):
			h=0.0
			for a in range(M):
				for b in range(N):
					l=((float(i*a)/M)+ (float(j*b)/N))
					h += x[a,b]*np.exp(-2j*np.pi*l)

			trans[i,j]=h/M/N
	return trans

# inversa para comprobar que la transformada anterior funcione

def inversa( x ):

    global M
    global N
    mat = np.zeros((M,N),dtype=float)
    
    for a in range(M):
        for b in range(N):
            z = 0.0
            for i in range(M):
                for j in range(N):
                    l=(float(i*a)/M + float(j*b)/N) 
                    z += x[i,j]*np.exp(2j*np.pi*l)
            mat[a,b] = z.real
    return mat

# funcion que deja pasar las frecuencias altas

def altos(mat):	

	global M
	global N

	for i in range(M):
		for j in range(N):
			if ( mat[i,j] < 0.025):
				mat[i,j]=0

	return mat

def bajos(mat):

	global M
	global N
	
	for i in range(M):
		for j in range(N):
			if (mat[i,j] > 0.025):

				mat[i,j]=0

	return mat

def gaussK(n_pixel_kernell):

	global M
	global N

	x, y = np.meshgrid(np.linspace(0.0,N-1,N), np.linspace(0.0,M-1,M))
	m=0.0
	j= np.sqrt(x*x+y*y)
	u= np.exp(-((j-m)**2/(2.0*n_pixel_kernell**2)))
			
	return u



def reconocer(alto_bajo):

	if(alto_bajo== "alto"):

		pasaAltos= altos(fourier2d(a))
		K= fourier2d(gaussK(n_pixel_kernell))

		final= inversa(pasaAltos*K)

		plt.figure()

		plt.imshow(final, cmap="gray")
		plt.imsave("Altas.png", final[:,:], cmap= plt.cm.gray)

	elif (alto_bajo== "bajo"):


		pasaBajos= bajos(fourier2d(a))
		K= fourier2d(gaussK(n_pixel_kernell))

		final= inversa(pasaBajos*K)

		plt.figure()

		plt.imshow(final, cmap="gray")

		plt.imsave("Bajas.png", final[:,:], cmap= plt.cm.gray)

reconocer(alto_bajo)
		
	

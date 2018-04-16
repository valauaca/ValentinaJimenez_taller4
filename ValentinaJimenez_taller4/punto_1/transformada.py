import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import cv2
from scipy import misc
from scipy import fftpack


# abrir imagen

def abrir_byn(img):

	imagen = Image.open(img)
	imagenrgb= imagen.convert("RGB")
	imagenbn=imagen.convert("L")
	imagenbn.save("blancoynegro.png")
	array= plt.imread("blancoynegro.png")
	return array

a=abrir_byn("hongo.png")
print "La matriz de la imegn es: ", a



# funcion para hacer la transformada de fourier en dos dimensiones

def fourier2d (x):


	M = np.shape(x[0])
	N =np.shape(x[1])
	# arreglo de ceros al cual pueden entrar numeros complejos
	trans= np.zeros(np.shape(x), dtype =np.complex)
	
	for i in range (len(M)):

		for j in range(len(N)):
			h=0
			for a in range (len(M)):
				for b in range(len(N)):
					l=((i*a/3.0)+ (j*b/3.0))
					h += x[a,b]*np.exp(-2j*np.pi*l)
				
			trans[i,j]=h
	return trans


x = np.matrix([[1,2,3],[4,5,6],[7,8,9]])

print "paquete", fftpack.fft2(a, axes=(0,1))
print "resultado:", fourier2d(a)



	

	
	

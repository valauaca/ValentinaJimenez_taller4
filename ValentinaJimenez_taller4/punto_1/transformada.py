import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from scipy import misc
from scipy import fftpack


# abrir imagen, metopdo sacado de 

def abrir_byn(img):

	imagen = Image.open(img)
	imagenrgb= imagen.convert("RGB")
	imagenbn=imagen.convert("L")
	imagenbn.save("blancoynegro.png")
	array= plt.imread("blancoynegro.png")
	return array

a=abrir_byn("hongo.png")
print "La matriz de la imagen es: ", a


# funcion para hacer la transformada de fourier en dos dimensiones

def fourier2d (x):
	global M,N

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
    global M,N
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


tf= fourier2d(a)
b= inversa(tf)
print "RESULTADO", b 

plt.imshow(b, cmap=plt.cm.Greys)
plt.show()

def gaussK():

	global M,N
	x= np.linspace(0.0, N-1,N)
	y= np.linspace(0.0, M-1,M)
	sigma=1.0
	m=0.0
	
	j= np.sqrt(x*x+y*y)
	u= np.exp(-((j-m)**2/(2.0*sigma**2)))
			
	return (u)
	

K=fourier2d(gaussK())

final=inversa(k*ft)

print final
plt.figure()
plt.imshow(final, cmap="gray")






	




	

	
	

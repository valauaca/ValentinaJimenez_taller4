import cv2
import numpy as np
from scipy.signal import convolve2d
from scipy import fftpack
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import cv2
from scipy import misc
from scipy import fftpack


# funcion que lee cualquier imagen


def abrir_byn(img):

	imagen = Image.open(img)
	imagenrgb= imagen.convert("RGB")
	imagenbn=imagen.convert("L")
	imagenbn.save("blancoynegro.png")
	array= plt.imread("blancoynegro.png")
	return array

a=abrir_byn("hongo.png")
print "La matriz de la imegn es: ", a



def transformada(mtz):

	(M,N)=np.shape(mtz)

	trans=np.zeros((M,N),dtype=complex)
	k=np.linspace(0.0,N-1,N)
	j=np.linspace(0.0, M-1, M)
	for m in range(M):
		for n in range(N):
			a=k*(float(n)/float(N))
			print len(a)
			b=j*(float(m)/float(M))
			print len(b)
			exp= (-1j)*(2.0)*(np.pi)*(float(a+b))
			transfor += mtz[m,n]*np.exp(exp)
		trans[m,n]=transfor

	return trans


transformada(a)







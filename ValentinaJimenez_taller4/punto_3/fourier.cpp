#include <iostream> 
#include <fstream> 
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

double** arreglo2D(int M);
void borrar_arreglo(double** mat, int N);
int dimensiones(char* nombre, int &columnas, int &filas);
void cargar_datos (char* nombre, double** datos, int columnas, int filas);




// funcion que encuentra la dimesion de los datos (num filas y num de columnas) 

int dimensiones(char* nombre, int &columnas, int &filas){

	ifstream datos("datos.txt");

	// para hallar columnas

	string primera;

	getline(datos, primera);
	columnas=0;
	
	for (int i =0; i < primera.size(); i++)

		columnas += (primera[i] != ' ')? 1:0;

	// para hallar las filas 

	filas=0;
	string numero;

	while (!datos.eof()){
		getline(datos, numero);
		filas += 1;

	}

}

//funcion que cra las direcciones para cargar los datos

void cargar_datos (char* nombre, double** datos, int columnas, int filas){

	ifstream file("datos.txt");
	double x[filas*columnas];

	for (int i=0; i < filas*columnas; i++){

		file >> x[i];
	}
	
	for (int i =0; i < filas; i ++){
		for(int j=0; j<columnas; j++){

		datos[i][j]= x[i*columnas+j];
		}
		
	}
}


	
// crea n arreglo en dos dimensiones para retornar los datos

double** arreglo2D(int M){
	double **datos;
	datos=new double*[M];
	for (int i=0; i < M; i++)
		datos[i]=new double[M];
	return datos;
}

// borra el areglo de la memoria

void borrar_arreglo(double** mat, int N){
	for (int i=0; i <N; i++){
		delete[] mat[i];
	delete[] mat;
	}
}


void agregar(char* nombre, double** datos, int columnas, int filas){


	datos= arreglo2D(filas);
	cargar_datos(nombre, datos, columnas, filas);

	for (int i =0; i < filas-1; i++){

		for (int j =0; j<columnas; j++){
			cout << datos[i][j]<<" ";
		}
		cout << endl;
	}

	borrar_arreglo( datos, filas);
	

}

double* linspace(double*l, int xi, int xf, int N){

	double d= (xf-xi)/(N-1.0);
	for( int i=0; i<N; i++){
		l[i]=(i*d);

	}
	return l;

}


// lagrange


double* lagrange(double* x, double* y, double* xnuevo, double* ynuevo, int N){


	//linspace
	
	for (int k=0; k<N; k++){

		double resultado=1.0;
		for (int i =0; i<N; i++){

			double v= y[i];
			for (int j =0; j<N; j++){

				if ( i!=j){
					v *= (xnuevo[k]-x[j])/(x[i]-x[j]);
					resultado += v;
				}
			}
			
		}
		ynuevo[k]= resultado-1.0;
	}
	return ynuevo;
}


double* fourier( double* R, double* I, double* xnuevo, double* ynuevo, int N){

	double real= 0.0;
	double imaginario= 0.0;

	for (int i= 0; i< N; i++){
		for (int j=0; j<N; j++){
			real += ynuevo[j] * cos((-2.0*3.1416*i*j)/N);
			imaginario += ynuevo[j] * sin((-2.0*3.1416*i*j)/N);
			R[j]= real;
			I[j]= imaginario;
			cout << R[j] << "  " << I[j] << endl;
		}
	}
	return R, I;


}

double* frecuencias ( double* frec, double* R, double* I, int N){

for (int i =0; i<N; i++){
		double g=(R[i]*R[i])+ (I[i]*I[i]);
		double S= pow(g,0.5);
		frec[i] = S;
		cout<<frec[i]<< " " << endl;
	}
	return frec;

}




// funcion principal


int main(int arg, char* argv[]){

	int m=0, n=0;
	dimensiones(argv[1], m, n);
	double** data;
	data= arreglo2D(n);
	cargar_datos(argv[1],data, m, n);

	double x[n];
	double y[n];

	for (int i=0; i<(n-1); i++){
		x[i]=data[i][0];
		y[i]=data[i][1];
	}
	double xi=x[0];
	double xf=x[n-2];
	
	double xnuevo[n];
	linspace( xnuevo, xi, xf, n-1);
	double ynuevo[n];

	lagrange(x,y, xnuevo, ynuevo,  n-1);
	double R[n-1];
	double I[n-1];
	double frec[n-1];
	cout<< "Parte real: " << " " << " parte Imaginaria: " << " " <<endl;
	fourier( R, I, xnuevo, ynuevo, n-1);

	cout << "Frecuencias"<< endl;

	frecuencias(frec, R, I, n-1);


	
}	


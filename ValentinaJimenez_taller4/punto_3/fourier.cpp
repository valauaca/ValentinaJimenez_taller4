#include <iostream> 
#include <fstream> 
#include <string>

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

// cargar columna 1
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



// funcion principal


int main(int argc, char* argv[]){

	int m=0, n=0;
	dimensiones(argv[1], m, n);

	double **datos;
	datos= arreglo2D(n);
	cargar_datos(argv[1], datos, m, n);

	for (int i =0; i < n-1; i++){

		for (int j =0; j<m; j++){
			cout << datos[i][j]<<" ";
		}
		cout << endl;
	}

	borrar_arreglo( datos, n);
	return 0;
}



// lagrange


double lagrange(X,Y){

	N= x.shape[0]

	//linspace
	double polinomio[N];


	for (int i=0; i<N; i++){

		polinomio[i]=0.0
	}
	
	for (int k=0; k<N; k++){

		resultado=1.0;
		for (int i =0; i<N; i++){

			v= Y[i]
			for (int j =0; j<N; j++){

				if ( i!=j){
					v *= (X[k]-X[j])/(X[i]-X[j]);
				}
			}
			resultado += v;
		}
		polinomio[k]= resultado-1;
	}
	return x, pol;
}






		
	



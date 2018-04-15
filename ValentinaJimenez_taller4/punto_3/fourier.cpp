#include <iostream> 
#include <fstream> 
#include <string>

using namespace std;


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

	cout << " " << columnas << " " << filas << endl;

}
void cargar_datos (char* nombre, double** datos, int columnas, int filas){

	ifstream file("datos.txt");
	double valor;
	double x[filas*columnas];
	for (int i=0; i < filas*columnas; i++){

		file >> x[i];
	}
	for (int i =0; i < filas; i ++){

		for (int j =0; j< columnas; j++){

			datos[i][j]= x[i*columnas+j];


		}
	}
}


double** arreglo2D(int M){
	double **datos;
	datos=new double*[M];
	for (int i=0; i < M; i++)
		datos[i]=new double*[M];
	return datos;
}


void borrar_arreglo(double** mat, int N){
	for (int i=0; i <N; i++){
		delete[] mat[i];
	delete[] mat;
	}
}

int main(int argc, char* argv[]){

	int m=0, n=0;
	dimensiones(argv[1], m, n);

	double **datos;
	datos= arreglo2D(n);
	cargar_datos(argv[1], datos, m, n);

	for (int i =0; i < n; i++){

		for (int j =0; j<n; j++){
			cout << datos[i][j]<<" ";
		}
		cout << endl;
	}

	borrar_arreglo( datos, n);
	return 0;
}
		





		
	



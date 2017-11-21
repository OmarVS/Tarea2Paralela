#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <limits.h>
#include <cstring>
#include <math.h>

using namespace std;

char *ptr;

typedef char cadena[30];

typedef struct
{
  float x;
  float y;
}punto;

typedef struct
{
  int a;
  int b;
  int c;
}triangulo;

punto coordenada[5000];
triangulo triangulos[9665];

float distancia_xy (float x, float y)
{
  return sqrt(pow(x,2)+pow(y,2));
}

punto buscar_punto(int indice, punto coordenada[])
{
  return coordenada[indice];
}

int leer_triangulo(cadena archivo){
  ifstream fs;
        fs.open(archivo);
        if (!fs) cout<<"El fichero no existe o no se puede leer.\n";
        else {
	        long long cont=0;
           	cadena string;
           	cout<<"Leyendo el fichero..."<<endl;

           	while(!fs.eof())
	        {
              int cont2=0;
           		cont++;
           		fs.getline(string,30,'\n');
           		//cout<<"Dato sin separar: "<<string<<endl;
           		ptr = strtok(string," ");
           		while(ptr != NULL)
                   {

                    //cout <<"Dato separado:"<< ptr << endl;
                    int d=atoi(ptr);
                    //cout <<"Dato separado en FLOAT:"<< d << endl;
                    if (cont2==0){
                    triangulos[cont].a = d;
                      }
                    if (cont2==1){
                    triangulos[cont].b = d;
                     }
                    if (cont2==2){
                    triangulos[cont].c = d;
                     }
                    ptr = strtok(NULL, " ");
                    cont2++;
                   }
           	}
            return cont-1;
        }
}

int leer_coordenadas(cadena archivo)
{
	ifstream fs;
        fs.open(archivo);
        if (!fs) cout<<"El fichero no existe o no se puede leer.\n";
        else {
	        long long cont=0;
           	cadena string;
           	cout<<"Leyendo el fichero..."<<endl;

           	while(!fs.eof())
	        {
              int cont2=0;
           		cont++;
           		fs.getline(string,30,'\n');
           		//cout<<"Dato sin separar: "<<string<<endl;
           		ptr = strtok(string," ");
           		while(ptr != NULL)
                   {

                    //cout <<"Dato separado:"<< ptr << endl;
                    float d=atof(ptr);
                    //cout <<"Dato separado en FLOAT:"<< d << endl;
                    if (cont2==1){
                    coordenada[cont].x = d;
                      }
                    if (cont2==2){
                    coordenada[cont].y = d;
                     }
                    ptr = strtok(NULL, " ");
                    cont2++;
                   }
           	}

           	return cont-1;
        }

}



int main(int argc, char *argv[])
{

    if(argc<2)    cout<<"Ingrese la ruta del archivo como argumento. Ejemplo: \"./tarea1 numeros.csv\""<<endl;
    else{
    	cout<<"el archivo tiene: "<<leer_coordenadas(argv[1])<<" lineas"<<endl;

    	cout <<"DATO X EN STRUC 4999 PRUEBA:"<< coordenada[4999].x << endl;
        cout <<"DATO Y EN STRUC 9 PRUEBA:"<< coordenada[9].y << endl;
        cout <<"DATO X EN STRUC 3 PRUEBA:"<< coordenada[3].x << endl;
        cout<<"el triangulo tiene: "<<leer_triangulo(argv[2])<<" lineas"<<endl;
    }
    return 0;
}

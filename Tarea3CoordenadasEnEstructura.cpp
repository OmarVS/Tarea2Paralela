#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <limits.h>
#include <cstring>
#include <math.h>

using namespace std;
typedef char cadena[30];

typedef struct
{
  float x;
  float y;
}punto;

float distancia_xy (float x, float y)
{
  return sqrt(pow(x,2)+pow(y,2));
}

punto buscar_punto(int indice, punto coordenada[])
{
  return coordenada[indice];
}



int main(int argc, char *argv[])
{
  punto coordenada[5000];
	char *ptr;
    if(argc<2)    cout<<"Ingrese la ruta del archivo como argumento. Ejemplo: \"./tarea1 numeros.csv\""<<endl;
    else{
       	ifstream fs;
        fs.open(argv[1]);
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
            //cout <<"DATO X EN STRUC 4999 PRUEBA:"<< coordenada[4999].x << endl;
            //cout <<"DATO Y EN STRUC 9 PRUEBA:"<< coordenada[9].y << endl;
            //cout <<"DATO X EN STRUC 3 PRUEBA:"<< coordenada[3].x << endl;

           	int lineas= cont-1;
           	cout<<"Lineas en el fichero: "<<lineas<<endl; 

         
            
        }
    }
    return 0;
}
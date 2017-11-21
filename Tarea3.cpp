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

float distancia_xy (punto p, punto q)
{
  return sqrt(pow((q.x - p.x),2)+pow((q.y - p.y),2));
}

punto buscar_punto(int indice)
{
  return coordenada[indice-1];
}

float calcular_perimetro(triangulo t)
{
  punto puntos[3];
  float distancia[3];

  puntos[0] = buscar_punto(t.a);
  puntos[1] = buscar_punto(t.b);
  puntos[2] = buscar_punto(t.c);

  distancia[0] = distancia_xy(puntos[0], puntos[1]);
  distancia[1] = distancia_xy(puntos[1], puntos[2]);
  distancia[2] = distancia_xy(puntos[0], puntos[2]);

  return distancia[0] + distancia[1] + distancia[2];

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
              //cont++;
           		fs.getline(string,30,'\n');
           		//cout<<"Dato sin separar: "<<string<<endl;
           		ptr = strtok(string," ");
           		while(ptr != NULL)
                   {
                    //cout <<"Dato separado:"<< ptr << endl;
                    int d=atof(ptr);
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
                		cont++;
           	}
            cout<<"triangulo a:"<<triangulos[1].a<<endl;
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
           		//cont++;
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
                   cont++;
           	}
           	return cont-1;
        }
}

int main(int argc, char *argv[])
{

    if(argc<2)    cout<<"Ingrese la ruta del archivo como argumento. Ejemplo: \"./tarea1 numeros.csv\""<<endl;
    else{
    	cout<<"el archivo tiene: "<<leer_coordenadas(argv[1])<<" lineas"<<endl;
      leer_triangulo(argv[2]);
      cout<<"triangulo 0 a: "<<triangulos[0].a<<endl;
      cout<<"El perimetro del triangulo 0 es: "<<calcular_perimetro(triangulos[1])<<endl;
    }
    return 0;
}
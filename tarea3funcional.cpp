#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <limits.h>
#include <cstring>
#include <math.h>
#include "mpi.h"

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
            cout<<"Leyendo el fichero de triangulos..."<<endl;

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
            //cout<<"triangulo a:"<<triangulos[1].a<<endl;
            return cont-1;
        }
}

void leer_coordenadas(cadena archivo)
{
  ifstream fs;
        fs.open(archivo);
        if (!fs) cout<<"El fichero no existe o no se puede leer.\n";
        else {
          long long cont=0;
            cadena string;
            cout<<"Leyendo el fichero de puntos..."<<endl;

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
        }
}

int main(int argc, char *argv[])
{
  cout.precision(10);
  int status, my_rank, cant;  /* Valor de retorno, id, cant */
  int limites[2],valor;
  float acum=0, total = 0;
  MPI_Status rec_stat; /* Status object*/

  leer_coordenadas(argv[1]);

  valor=leer_triangulo(argv[2]);

  MPI_Init(&argc, &argv); /* Inicio de MPI */
  MPI_Comm_size(MPI_COMM_WORLD, &cant);      /* numero de procesos */
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); /* rango de procesos  */

  valor = (valor/cant)+1;

    if(argc<2)    cout<<"Ingrese la ruta de los archivos como argumento. Ejemplo: \"./tarea3 puntos triangulos\""<<endl;

    else{

      if(my_rank==0){
        for(int i=0; i<cant; i++)
        {
          limites[0] = valor*i;
          limites[1] = (valor*(i+1))-1;
          status = MPI_Send(limites, 2, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        status = MPI_Recv(&limites, 2, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &rec_stat);

        for(int i=limites[0];i<=limites[1];i++){
          acum+=calcular_perimetro(triangulos[i]);
        }

        MPI_Reduce(&acum, &total, 1, MPI_FLOAT, MPI_SUM, 0,MPI_COMM_WORLD);
        
        cout<<"La suma de todos los perimetros es: "<<total<<endl;
      }

      else{
        status = MPI_Recv(&limites, 2, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &rec_stat);

        for(int i=limites[0];i<=limites[1];i++){
          acum+=calcular_perimetro(triangulos[i]);
        }
        
        MPI_Reduce(&acum, &total, 1, MPI_FLOAT, MPI_SUM, 0,MPI_COMM_WORLD);
       
      }
    }
    MPI_Finalize();
    return 0;
}
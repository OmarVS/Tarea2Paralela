#include <iostream>
#include <stdlib.h>
#include <math.h>
//#include <mpi.h>

using namespace std;

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
	cout.precision(3);
	punto coordenada[5000];

	coordenada[0].x = 5.5;
	coordenada[0].y = 3.2;
	cout<<"coordenada x: "<<coordenada[0].x<<" coordenada y: "<<coordenada[0].y<<endl;
	cout<<"Distancia entre los puntos X e Y: "<<distancia_xy(coordenada[0].x,coordenada[0].y)<<endl;

	/*uso de buscar_punto
	int i;
	cout<<en la posicion <<i<<": X = "<<buscar_punto(i, coordenada).x<<", Y = "<<buscar_punto(i, coordenada).y<<endl;
	*/
}

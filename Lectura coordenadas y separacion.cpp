#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <limits.h>
#include <cstring>

using namespace std;
typedef char cadena[30];

int main(int argc, char *argv[])
{
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
           		cont++;
           		fs.getline(string,30,'\n');
           		cout<<"Dato sin separar: "<<string<<endl; 
           		ptr = strtok(string," ");
           		while(ptr != NULL)
                   {
                    cout <<"Dato separado:"<< ptr << endl;
                    ptr = strtok(NULL, " ");
                   }
           	}

           	int lineas= cont-1;
           	cout<<"Lineas en el fichero: "<<lineas<<endl; 

         
            
        }
    }
    return 0;
}
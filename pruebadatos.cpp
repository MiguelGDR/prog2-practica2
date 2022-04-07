#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Estudiante.hpp"

using namespace std;
using namespace bblProgIIB;

int main(){
    ifstream flujo_ent;
    string linea;
    string deporte;
    char delim = ',';

    int e;
    char s;
    
    flujo_ent.open("campus1.txt");

    while(getline(flujo_ent,linea)){ // Nombre
        cout << linea << endl;

        getline(flujo_ent,linea);   // DNI
        cout << linea << endl;

        flujo_ent >> e;             // Edad
        cout << e << endl;

        flujo_ent >> s;            // Sexo 
        cout << s << endl;

        getline(flujo_ent,linea);   // Finalizo linea

        getline(flujo_ent,linea);   // Grado
        cout << linea << endl;

        getline(flujo_ent,linea);   // Deportes: Fútbol Sala, Voleibol, Baloncesto, Natación, Atletismo
        stringstream ss(linea);             // Guardo el string en otro flujo para poder recorrerlo con 
        while(getline(ss,deporte,',')){     // el delimitador ',' y así separar los deportes.
            cout << deporte << endl;
        }
    } 

    flujo_ent.close();
    return 0;
}
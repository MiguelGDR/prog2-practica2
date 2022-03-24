#include "Estudiante.hpp"
#include <iostream>

using namespace std;
using namespace bblProgIIB;

int main(){
    Estudiante est1;

    est1.asignarDNI("71207351H");
    est1.asignarEdad(21);
    est1.asignarGrado("Sonido e Imagen");
    est1.asignarNombre("Miguel");
    est1.asignarSexo('m');

    int edad = est1.obtenerEdad();
    cout << "El estudiante 1 tiene " << edad << ", y su DNI es " << est1.obtenerDni() << endl;

    Estudiante est2 (est1);

    int edad2 = est2.obtenerEdad();
    string grado2 = est2.obtenerGrado();

    cout << "El estudiante 2 tiene " << edad2 << " y estudia " << grado2 << endl; 

    est2.asignarNombre("Bochan ChupaPijas");
    est2.asignarDNI("69696969Y");

    cout << endl << endl;

    est1.mostrar();
    est2.mostrar();

    system("pause");
    return 0;
}
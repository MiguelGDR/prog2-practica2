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
    Estudiante est3;

    est3.mostrar();

    est3 = est1;

    est1.mostrar();
    est2.mostrar();
    est3.asignarNombre("Enrique");
    est3.mostrar();

    if(est1 == est3){
        cout << "Son iguales" << endl;
    }

    system("pause");
    return 0;
}
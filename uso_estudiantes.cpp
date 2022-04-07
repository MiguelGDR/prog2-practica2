#include "Estudiante.hpp"
#include "ListaEstudiantes.hpp"
#include <iostream>

using namespace std;
using namespace bblProgIIB;

int main(){
    Estudiante est1;
    ListaEstudiantes lista1;

    lista1.obtenerDatos("campus1.txt");

    lista1.mostrarLista();

    system("pause");
    return 0;
}
#include "Estudiante.hpp"
#include "ListaEstudiantes.hpp"
#include <iostream>

using namespace std;
using namespace bblProgIIB;

int main(){
    Estudiante est1;
    ListaEstudiantes lista1;
    ListaEstudiantes listadeportes;
    TDeportes dep;
    dep.numdep = 2;

    lista1.obtenerDatos("campus1.txt");

    listadeportes = lista1.numerodeportes(dep);
    

    lista1.mostrarLista();

    system("pause");
    return 0;
}
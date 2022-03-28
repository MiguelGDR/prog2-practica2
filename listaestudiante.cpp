#include "ListaEstudiantes.hpp"
#include <cassert> 
#include <iostream>

using namespace std;

namespace bblProgIIB{
// Contructores y Destructor
    // Constructor por defecto
    ListaEstudiantes::ListaEstudiantes() : lista(), num(0)
    {
    }

    // Contructor definido
    ListaEstudiantes::ListaEstudiantes(const ListaEstudiantes &otra_lista) : lista(otra_lista.lista){
    }

    // Destructor
    ListaEstudiantes::~ListaEstudiantes(){
    }

// Implementación de los métodos
    void ListaEstudiantes::vaciar(){

    }

    bool ListaEstudiantes::esta_vacia() const{
        return num == 0;
    }

    bool ListaEstudiantes::esta_llena() const{
        return num == unsigned(lista.size());
    }

    unsigned ListaEstudiantes::numeroEstudiantes() const{
        return num;
    }

    void ListaEstudiantes::insertar(unsigned indice, const Estudiante &nuevo_elemento){
        assert(indice >= 0 && indice < num && (!esta_llena()));

        for (unsigned pos = num; pos > indice; --pos){  // Abro hueco para insertar al nuevo estudiante, desplazando al resto
            lista[pos] = lista[pos - 1];                // una posición a la derecha.
        }  

        lista[indice-1] = nuevo_elemento;               // Añado al estudiante
        num+1;
    }

    void ListaEstudiantes::eliminar(unsigned indice){
        assert(indice >= 0 && indice < num);
        for (unsigned pos = indice; pos < num; pos++){   // Elimino el elemento deseado moviendo todos los elementos posteriores 
            lista[pos] = lista[pos + 1];                 // una posición menos.
        }  
    }

    void ListaEstudiantes::consultar(unsigned indice, Estudiante &elemento) const{
        assert(indice >= 0 && indice < num);
        elemento = lista[indice];
    }
}
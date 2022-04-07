#include "ListaEstudiantes.hpp"
#include "Estudiante.hpp"
#include <cassert> 
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace bblProgIIB{
// Contructores y Destructor
    // Constructor por defecto
    ListaEstudiantes::ListaEstudiantes() : lista(), num(0){
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
        assert(indice < num && (!esta_llena()));

        for (unsigned pos = num; pos > indice; --pos){  // Abro hueco para insertar al nuevo estudiante, desplazando al resto
            lista[pos] = lista[pos - 1];                // una posición a la derecha.
        }  

        lista[indice-1] = nuevo_elemento;               // Añado al estudiante
        num++;
    }

    void ListaEstudiantes::eliminar(unsigned indice){
        assert(indice < num);
        for (unsigned pos = indice; pos < num; pos++){   // Elimino el elemento deseado moviendo todos los elementos posteriores 
            lista[pos] = lista[pos + 1];                 // una posición menos.
        }  
    }

    void ListaEstudiantes::consultar(unsigned indice, Estudiante &elemento) const{
        assert(indice < num);
        elemento = lista[indice];
    }

// Implementación de los operadores 
     //Operador de asignación  
        ListaEstudiantes &ListaEstudiantes::operator=(const ListaEstudiantes &otraLista){
            if (this != &otraLista)
            {
                lista = otraLista.lista;
                num = otraLista.num;
            }
            return *this;
        }
    //Operador de comparación de igualdad
        bool ListaEstudiantes::operator==(const ListaEstudiantes &otra) const{
            bool ok = num == otra.num;
            unsigned i = 0;
            
            while(ok && i < num){
                ok = lista[i] == otra.lista[i];
                i++;
            }
            return ok;
        }

        bool ListaEstudiantes::obtenerDatos(const std::string &fichero){
            ifstream flujo_ent;
            string linea;
            string deporte; // Usado para guardar cada deporte por separado
            TDeportes dep;
            int d;  // Para el indice de deporte
            int e;  // Para guardar la edad
            char s; // Para guardar el sexo

            int i = 0;  // Usado en el bucle
            flujo_ent.open(fichero);

            if(flujo_ent.fail()){
                return false;
            }

            while(getline(flujo_ent,linea)){    // Si lee linea, que repita el bucle. Si lee, es el nombre.
                lista[i].asignarNombre(linea);  // Guardo nombre

                getline(flujo_ent,linea);       // Leo DNI
                lista[i].asignarDNI(linea);     // Guardo DNI

                flujo_ent >> e;                 // Leo edad
                lista[i].asignarEdad(e);        // Guardo edad

                flujo_ent >> s;                 // Leo sexo
                lista[i].asignarSexo(s);        // Guardo sexo

                getline(flujo_ent,linea);       // Realizo el getline para finalizar la linea de la edad y sexo
                                                // y asi queda el flujo queda preparado para leer el grado en la
                                                // la siguiente lectura con getline().
                getline(flujo_ent,linea);       // Leo grado
                lista[i].asignarGrado(linea);   // Guardo grado

                getline(flujo_ent,linea);   // Deportes: Fútbol Sala, Voleibol, Baloncesto, Natación, Atletismo
                stringstream ss(linea);             // Guardo el string en otro flujo para poder recorrerlo con 
                d = 0;  // Preparo d para usarlo en el while posterior
                while(getline(ss,deporte,',')){     // el delimitador ',' y así separar los deportes.
                    dep.deportes[d] = deporte;
                    lista[i].asignarDeportes(dep);  // Guardo el deporte
                    d++;
                }
                num = i+1;    // Tamaño de la lista
                i++;    // Preparo el siguiente indice 
            }
            flujo_ent.close();
            return true;
        }   // Fin de la implementacion de obtenerDatos

        bool ListaEstudiantes::guardarDatos(const std::string &fichero){
            ofstream flujo_sal;
            flujo_sal.open(fichero);
            
            if(flujo_sal.fail()){
                return false;
            }

            

            flujo_sal.close();
            return true;
        }

        unsigned ListaEstudiantes::numerodeportes(){
            unsigned contdep = 0;
            for(unsigned i=0; i<lista.size(); i++){
                if(lista[i].obtenerDeportes().numdep != 0){
                    contdep++;
                }
            }
            return contdep;
        }

        /*ListaEstudiantes ListaEstudiantes::practica(TDeportes deportes){
            
        }*/

       /* Estudiante ListaEstudiantes::menorEdad(){
            int est;
            for(unsigned i=0; i<lista.size(); i++){
                lista[i].obtenerEdad();
            }

            return lista[est];
        }*/

        void ListaEstudiantes::mostrarLista(){
            int dep=0;
            for(unsigned i = 0; i<lista.size(); i++){
                cout << lista[i].obtenerNombre() << endl;
                cout << lista[i].obtenerDni() << endl;
                cout << lista[i].obtenerEdad() << " " << lista[i].obtenerSexo() << endl;
                cout << lista[i].obtenerGrado() << endl;
                if(lista[i].obtenerDeportes().numdep != 0){
                    cout << lista[i].obtenerDeportes().deportes[dep] << "," << lista[i].obtenerDeportes().deportes[dep+1] << "," << lista[i].obtenerDeportes().deportes[dep+2] << endl;
                }
            }
        }
}
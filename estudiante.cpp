#include "Estudiante.hpp"
#include <cassert> 

namespace  bblProgIIB{
    // Constructor por defecto
    Estudiante::Estudiante() : nombre( ), dni(0), edad(0), sexo( ), grado( )
    {

    } // Fin del constructor por defecto

    // Constructor 
    Estudiante::Estudiante(const std::string &nNombre, const std::string &nDni, int nEdad, char nSexo, std::string nGrado, const TDeportes &nDeportes)
    : nombre(nNombre), dni(nDni), edad(nEdad), sexo(nSexo), grado(nGrado), deportes(nDeportes)
    {
        assert(nEdad>0);
    } // Fin del constructor


    // Implementación de los métodos
    void Estudiante::asignarDNI(const std::string &d){
        dni = d;
    }

    void Estudiante::asignarNombre(const std::string &n){
        nombre =n;
    }

    void Estudiante::asignarEdad(int e){
        edad = e;
    }

    void Estudiante::asignarSexo(char s){
        sexo = s;
    }

    void Estudiante::asignarGrado(const std::string &g){
        grado = g;
    }

    void Estudiante::asignarDeportes(const TDeportes &dep){
        deportes = dep;
    }

} //Fin namespace bblProgIIB
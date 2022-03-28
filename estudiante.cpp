#include "Estudiante.hpp"
#include <cassert> 
#include <iostream>

using namespace std;

namespace  bblProgIIB{
// Contructores y Destructor
    // Constructor por defecto
    Estudiante::Estudiante(){
    } // Fin del constructor por defecto

    // Constructor definido
    Estudiante::Estudiante(const std::string &nNombre, const std::string &nDni, int nEdad, char nSexo, std::string nGrado, const TDeportes &nDeportes) : nombre(nNombre), dni(nDni), edad(nEdad), sexo(nSexo), grado(nGrado), deportes(nDeportes)
    {
        assert(nEdad>0);
    } // Fin del constructor

    // Constructor copia
    Estudiante::Estudiante(const Estudiante &otro) : nombre(otro.nombre), dni(otro.dni), edad(otro.edad), sexo(otro.sexo), grado(otro.grado), deportes(otro.deportes)
    {
    }// Fin del constructor copia

    // Destructor
    Estudiante::~Estudiante(){
    }
// Fin constructores y destructor

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

// Métodos para la práctica  "void mostrar() const"
    void Estudiante::mostrar() const{
        cout << endl;   // Para separar la información del estudiante de lo anterior escrito.
        cout << nombre << endl;
        cout << dni << endl;
        cout << edad << endl;
        cout << sexo << endl;
        cout << grado << endl;
    }

// Métodos get() para acceder a los atributos privados
    std::string Estudiante::obtenerDni() const{
        return dni;
    }

    std::string Estudiante::obtenerNombre() const{
        return nombre;
    }  

    int Estudiante::obtenerEdad() const{
        return edad;
    }            
    
    char Estudiante::obtenerSexo() const{
        return sexo;
    }
    
    std::string Estudiante::obtenerGrado() const{
        return grado;
    }
    
    TDeportes Estudiante::obtenerDeportes() const{
        return deportes;
    }

} //Fin namespace bblProgIIB
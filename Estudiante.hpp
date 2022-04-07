/******************************************************************************
 * Estudiante.hpp
 *
 * Módulo que contiene la clase Estudiante
 *
 * Programador:
 * Fecha:
 *****************************************************************************/

#ifndef __Estudiante_HPP__
#define __Estudiante_HPP__

#include <string>
#include <array>

namespace bblProgIIB
{
    const int MAX_DEP = 3;
    typedef std::array <std::string,MAX_DEP>TDep;

    typedef struct {
        TDep deportes;
        int numdep;
    }TDeportes;

    typedef struct
    {
	     uint16_t rojo, verde, azul;
     }TColor;

     const int ANCHO = 64;
     const int ALTO = 64;

     typedef std::array <TColor, ANCHO>TFila;
     typedef std::array <TFila, ALTO>TImag;

     typedef struct {
	    std::string tipo;
	    uint16_t alt,anc,mvc;
     }TCab;

     typedef struct
     {
	    TCab cabecera;
	    TImag imagen;
     }TImagen;

    class Estudiante {

    public:
      Estudiante();
      Estudiante(const std::string &nNombre, const std::string &nDni, int nEdad, char nSexo, std::string nGrado, const TDeportes &nDeportes);
      Estudiante(const Estudiante &otro);
      ~Estudiante();


        // Métodos básicos de consulta y manipulación
        void asignarDNI(const std::string &d);
        void asignarNombre(const std::string &n);
        void asignarEdad(int e);
        void asignarSexo(char s);
        void asignarGrado(const std::string &g);
        void asignarDeportes(const TDeportes &dep);
        void asignarFoto(const TImagen &i);
        std::string obtenerDni() const;     // Obtener: Como desde el main no puedo ver los atributos del
        std::string obtenerNombre() const;  // objeto (porque son privados), utilizo los métodos "obtener..."
        int obtenerEdad() const;            // (get()) para poder verlos y asi usarlos.
        char obtenerSexo() const;
        std::string obtenerGrado() const;
        TDeportes obtenerDeportes() const;
        TImagen obtenerFoto() const;

        // Métodos para la práctica
        void mostrar() const; // Muestra un estudiante por pantalla

        // Operadores
        Estudiante &operator=(const Estudiante &otro);
        bool operator==(const Estudiante &otro) const;

    private:

        std::string nombre;
        std::string dni;
        int edad;
        char sexo;
        std::string grado;
        TDeportes deportes;
        TImagen foto;

    }; // Fin Clase Estudiante
    
} // Fin bblProgIIB
#endif

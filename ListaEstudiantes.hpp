/******************************************************************************
 * listaEstudiantes.hpp
 *
 * Módulo que contiene la clase ListaEstudiantes
 *
 * Programador:
 * Fecha:
 *****************************************************************************/

#ifndef __LISTAESTUDIANTES_HPP__
#define __LISTAESTUDIANTES_HPP__

#include <string>
#include <array>
#include "Estudiante.hpp"

namespace bblProgIIB
{
    class ListaEstudiantes
    {
    public:
        ListaEstudiantes();
        // Constructor de copia
        ListaEstudiantes(const ListaEstudiantes &otra_lista);
        // Destructor de la lista
        ~ListaEstudiantes();

        void vaciar(); //¿Necesario?
        bool esta_vacia() const;
        bool esta_llena() const;
        unsigned numeroEstudiantes() const;
        void insertar(unsigned indice, const Estudiante &nuevo_elemento); // Usar índice comenzando en 0
        void eliminar(unsigned indice);                                   // Usar índice comenzando en 0
        void consultar(unsigned indice, Estudiante &elemento) const;      // Usar índice comenzando en 0

        ListaEstudiantes &operator=(const ListaEstudiantes &otraLista);
                            /* OPERADOR DE ASIGNACIÓN
                                Implementación
                            ListaEstudiantes &ListaEstudiantes::operator=(const ListaEstudiantes &otraLista)
                            {
                                if (this != &otralista)
                                {
                                    lista = otraLista.lista;
                                    num = otraLista.num;
                                }
                                return *this;
                            }*/

        bool operator==(const ListaEstudiantes &otra) const;
                            /* OPERADOR DE COMPARACIÓN DE IGUALDAD
                            Implementación
                            bool ListaEstudiantes::operator==(const ListaEstudiantes &otra) const
                            {
                                bool ok = num == otra.num;
                                unsigned i = 0;
                                while (ok && i < num)
                                {
                                    ok = lista[i] == otra.lista[i];
                                    i++;
                                }
                                return ok;
                            }
                            */

        bool obtenerDatos(const std::string &fichero); // ¿Se podría hacer un constructor que leyera el fichero para iniciar la lista?
        bool guardarDatos(const std::string &fichero);
        unsigned numerodeportes();
        ListaEstudiantes practica(TDeportes deportes);
        Estudiante menorEdad(); // Precondición: La lista no puede estar vacía
        void mostrarLista();

    private:
        static const unsigned MAX_ESTUDIANTES = 1000;  // 1000 estudiantes en la lista
        std::array<Estudiante, MAX_ESTUDIANTES> lista;
        unsigned num;
        // Métodos auxiliares
        // Devuelve la posición de un Estudiante, dado su DNI, o num si no está.
        unsigned buscarEstudiante(const std::string &dni) const; //Busca un Estudiante por dni

    }; // Fin class
} // Fin namespace
#endif

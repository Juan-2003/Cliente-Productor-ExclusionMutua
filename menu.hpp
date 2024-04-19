#include <string>
#include "entidad.hpp"

#ifndef menu_HPP_INCLUDED
#define menu_HPP_INCLUDED

class Menu{
    private:
        static int generarNumeroAleatorio(int);
        static void mostrarLista(Entidad*);
        static void mostrarSecuencia(int, Entidad*);

    public: 
        static void iniciar();

};
#endif
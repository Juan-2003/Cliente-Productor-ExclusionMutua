#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>
#include "entidad.h"

class Menu{
    private:
        static int generarNumeroAleatorio(int);
        static void mostrarLista(Entidad*);
        static void mostrarSecuencia(int, Entidad*);
        static void iniciarSecuencia(int elementos, Entidad* entidadPtr);

    public:
        static void iniciar();

};

#endif // MENU_H_INCLUDED

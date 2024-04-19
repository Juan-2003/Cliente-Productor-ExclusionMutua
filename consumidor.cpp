#include <windows.h>
#include "consumidor.hpp"
using namespace std;

Consumidor::Consumidor(): Entidad("Consumidor"){}

void Consumidor::quitarElemento(char* ptr){
    /*Para poder obtener el indice se hace una resta del puntero que
    llega menos la direccion de memoria de la posicion 0
    Si wey, eso se puede hacer.
    */
    int indice = ptr - &lista[0];
    lista[indice] = '_';
    /*Cada vez que se agrega un elemento, se recorre el puntero a la siguiente
    posicion
    */
    setPtr(&lista[indice+1]);
}

bool Consumidor::isListaDisponible(){
    for(char n : lista){
        if(n == '*'){
            return true;
        }
    }
    return false;
}
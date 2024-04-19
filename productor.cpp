#include "productor.hpp"
using namespace std;

Productor::Productor(): Entidad("Productor"){}

void Productor::agregarElemento(char* ptr){
    /*Para poder obtener el indice se hace una resta del puntero que
    llega menos la direccion de memoria de la posicion 0
    Si wey, eso se puede hacer.
    */
    
    int indice = ptr - &lista[0];
    lista[indice] = '*';
    /*Cada vez que se agrega un elemento, se recorre el puntero a la siguiente
    posicion
    */
    setPtr(&lista[indice+1]);
}

bool Productor::isListaDisponible(){
    for(char n : lista){
        if(n == '_'){
            return true;
        }
    }
    return false;
}
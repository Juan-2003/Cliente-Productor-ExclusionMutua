#include "productor.hpp"
using namespace std;

Productor::Productor(): Entidad("Productor"){}

void Productor::ejecutarOperacion(){
    operacion('*');
}

bool Productor::ejecutarIsListaDisponible(){
    return isListaDisponible('_');
}
#include <windows.h>
#include "consumidor.hpp"
using namespace std;

Consumidor::Consumidor(): Entidad("Consumidor"){}

void Consumidor::ejecutarOperacion(){
    operacion('_');
}

bool Consumidor::ejecutarIsListaDisponible(){
    return isListaDisponible('*');
}
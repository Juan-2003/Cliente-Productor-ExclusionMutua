#include <windows.h>
#include "consumidor.h"
using namespace std;

Consumidor::Consumidor(): Entidad("Consumidor"){}

void Consumidor::ejecutarOperacion(){
    operacion('_');
}

bool Consumidor::ejecutarIsListaDisponible(){
    return isListaDisponible('*');
}

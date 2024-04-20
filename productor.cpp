#include "productor.h"
#include <windows.h>
using namespace std;

Productor::Productor(): Entidad("Productor"){}

void Productor::ejecutarOperacion(){
    operacion('*');
}

bool Productor::ejecutarIsListaDisponible(){
    return isListaDisponible('_');
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include "menu.h"
#include "entidad.h"
#include "productor.h"
#include "consumidor.h"

int main(){
     // Inicializar la semilla para la generaci�n de n�meros aleatorios
    srand(time(nullptr));
    Menu::iniciar();
    return 0;
}

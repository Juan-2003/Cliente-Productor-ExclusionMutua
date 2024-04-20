#include "entidad.hpp"
#include <algorithm>
using namespace std;

Entidad::Entidad(string tipoEntidad): tipoEntidad(tipoEntidad),
                                    estadoActual("Dormido"), 
                                    tiempoDormido(0.0){
        vector<char>lista;
                                    }

Entidad::Entidad(string tipoEntidad, string estadoActual): 
                                            tipoEntidad(tipoEntidad),
                                            estadoActual(estadoActual),
                                            tiempoDormido(0.0){}

Entidad::Entidad(string tipoEntidad, float tiempoDormido):
                                            tipoEntidad(tipoEntidad),
                                            estadoActual("Dormido"), 
                                            tiempoDormido(tiempoDormido){}

Entidad::Entidad(string tipoEntidad, string estadoActual, float tiempoDormido): 
                                        tipoEntidad(tipoEntidad),
                                        estadoActual(estadoActual),
                                        tiempoDormido(tiempoDormido){}

//Se define el vector 'lista'
vector<char> Entidad::lista;

// ------------------ SETTERS ------------------
void Entidad::setTipoEntidad(string tipoEntidad){
    this->tipoEntidad = tipoEntidad;
}

void Entidad::setEstadoActual(string estadoActual){
    this->estadoActual = estadoActual;
}

void Entidad::setTiempoDormido(float tiempoDormido){
    this->tiempoDormido = tiempoDormido;
}

void Entidad::setPtr(char* ptr){
    this->ptr = ptr;
}

void Entidad::setCantidadElementos(int cantidadElementos){
    this->cantidadElementos = cantidadElementos;
}

// ------------------ GETTERS ------------------
string Entidad::getTipoEntidad(){
    return this->tipoEntidad;
}

string Entidad::getEstadoActual(){
    return this->estadoActual;
}

int Entidad::getCantidadElementos(){
    return this->cantidadElementos;
}

float Entidad::getTiempoDormido(){
    return this->tiempoDormido;
}

//Regresa un puntero
char* Entidad::getPtr(){
    return ptr;
}


vector<char>& Entidad::getLista(){
    /*Se utiliza 'bandera' en 'static' para que sea posible solo
    redefinir el vector una vez.
    */
    static bool bandera = true;

    if(bandera){
        //Se establece el tamaño de la lista
        Entidad::lista.resize(22);
        //Se llena el vector en todas las posiciones con '_'
        fill(Entidad::lista.begin(), Entidad::lista.end(), '_');
        bandera = false;
    }
    return lista;
}

void Entidad::operacion(char elemento){
    /*Para poder obtener el indice se hace una resta del puntero que
    llega menos la direccion de memoria de la posicion 0
    Si wey, eso se puede hacer.
    */
    int indice = getPtr() - &lista[0];
    /*Cada vez que se agrega un elemento, se recorre el puntero a la siguiente
    posicion
    */
    if(indice > 21){
        setPtr(&lista[0]);
        *getPtr() = elemento;
        setPtr(&lista[*getPtr() - lista[0] +1]);
    }else{
        *getPtr() = elemento;
        setPtr(&lista[indice+1]);
    }
}

bool Entidad::isListaDisponible(char elemento){
    for(char n : lista){
        if(n == elemento){
            return true;
        }
    }
    return false;
}

string Entidad::toString(){
    return "Entidad: "+ tipoEntidad + "\n" +
            "Estado Actual: "+ estadoActual + "\n" +
            "Tiempo Dormido: "+ to_string(tiempoDormido);
}


                        

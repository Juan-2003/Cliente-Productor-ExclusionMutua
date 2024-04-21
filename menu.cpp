#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include "menu.h"
#include "entidad.h"
#include "consumidor.h"
#include "productor.h"

using namespace std;

/*
    El programa consta de la clase base 'Entidad' y las 2 clases 'Consumidor'
    y 'Productor', que son clases derivadas de 'Entidad'.
    Las 2 clases derivadas tienen acceso a todos los metodos y atributos
    de la clase 'Entidad'.

*/

//Se genera un numero aleatorio
int Menu::generarNumeroAleatorio(int n){
    return (n == 0)? rand() : (n == 1)? rand() % 4 + 3 : 0;
}

//Muestra la lista de la clase 'Entidad'
void Menu::mostrarLista(Entidad* tmp){
    int cont=0;
    vector<char>lista = tmp->getLista();
    for(char c : lista){
        if(cont > 8){
            cout<<c<<"  ";
        }else{
            cout<<c<<" ";
        }
        cont++;
    }
    cout<<endl;
    for(int i=1;i<23;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

void Menu::mostrarSecuencia(int elementos, Entidad* tmp){
    system("cls");

    mostrarLista(tmp);
    cout<<"Cantidad Elementos: "<<elementos<<endl;
    cout<<"Entidad: "<<tmp->getTipoEntidad()<<endl;
    Sleep(1000);
}

//Se inicia el programa
void Menu::iniciar(){
    Productor productor = Productor();
    Consumidor consumidor = Consumidor();
    vector<char>&lista = productor.getLista();
    Entidad* entidadPtr;
    productor.setPtr(&lista[0]);
    consumidor.setPtr(&lista[0]);

    while(true){
        //Numero aleatorio para elejir la siguiente entidad
        int numeroAleatorio = generarNumeroAleatorio(0);
        
        if(numeroAleatorio % 2 == 0){
            entidadPtr = &productor;
        }else{
            entidadPtr = &consumidor;
        }

        entidadPtr->setCantidadElementos(generarNumeroAleatorio(1));
        int elementos = entidadPtr->getCantidadElementos();
        system("cls");

        iniciarSecuencia(elementos, entidadPtr);

    }
}

void Menu::iniciarSecuencia(int elementos, Entidad* entidadPtr){
    for(int i = 0; elementos > 0; i++){ // EC: 5
        //Terminar programa
        if(_kbhit()){
            if( _getch() == 27){
                exit(0);
            }
        }
        mostrarSecuencia(elementos,entidadPtr);
        if(entidadPtr->ejecutarIsListaDisponible()){//Si hay espacio disponible entrara
            entidadPtr->ejecutarOperacion();
            elementos--;
            if(entidadPtr->getTipoEntidad() == "Consumidor" && elementos == 0){
                break;
            }
        }else{
            if(entidadPtr->getTipoEntidad() == "Consumidor"){
                elementos = 0;
            }
            break;
        }
    }
}



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
        if(cont>8){
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
    int elementos;

    system("cls");



    char tecla = '_';
    while(tecla != 'q'){
        static int i = 2;
        if(i % 2 == 0){
            entidadPtr = &productor;
        }else{
            entidadPtr = &consumidor;
        }

        entidadPtr->setCantidadElementos(generarNumeroAleatorio(1));
        elementos = entidadPtr->getCantidadElementos();

        while(elementos > 0 ){
            int elementosProductor;
            system("cls");
            elementosProductor = productor.getCantidadElementos();
            if(entidadPtr->getTipoEntidad() == "Productor"){
                for(int i = 0; i < elementos; i++){
                    mostrarSecuencia(elementos,entidadPtr);
                    if(productor.ejecutarIsListaDisponible()){
                        productor.ejecutarOperacion();
                        elementos--;
                    }else{
                        break;
                    }
                }
            }else{
                for(int i = 0; i < elementosProductor; i++){ // EC: 5
                    mostrarSecuencia(elementos,entidadPtr);
                    if(consumidor.ejecutarIsListaDisponible()){
                        consumidor.ejecutarOperacion();
                        elementos--;
                        if(elementos == 0){
                            break;
                        }
                    }else{
                        elementos = 0;
                        break;
                    }
                }
            }
            if(_kbhit()){
                tecla = _getch();
                break;
            }
        }
        i = generarNumeroAleatorio(0);
    }
}

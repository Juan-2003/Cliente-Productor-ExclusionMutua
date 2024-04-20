#include <iostream>
#include <vector>

#ifndef entidad_HPP_INCLUDED
#define entidad_HPP_INCLUDED

class Entidad{
    
    protected:
        /*Este vector es 'static' lo que significa que no pertence
         a ninguna instancia, sino a la misma clase. Asi que todos
         los objetos trabajarán sobre el mismo vector.
         El modificador de acceso es 'protected' para que esta clase
        y las clases derivadas tengan acceso a ella.
        */
        static std::vector<char>lista;

    private:
        std::string tipoEntidad; //Productor o Consumidor
        std::string estadoActual; //Dormido, trabajando, intentando acceder al contenedor
        float tiempoDormido; //Sleep
        char* ptr; //Apuntara a una posicion de la lista
        int cantidadElementos; //Cantidad de elementos a agregar / eliminar

    public:
        Entidad(std::string);
        Entidad(std::string, std::string);
        Entidad(std::string, float);
        Entidad(std::string, std::string, float);

        void setTipoEntidad(std::string);
        void setEstadoActual(std::string);
        void setTiempoDormido(float);
        void setPtr(char*);
        void setCantidadElementos(int);

        std::string getTipoEntidad();
        std::string getEstadoActual();
        int getCantidadElementos();
        float getTiempoDormido();
        char* getPtr();
        std::vector<char>& getLista();

        void operacion(char);
        virtual void ejecutarOperacion() = 0;

        bool isListaDisponible(char);
        virtual bool ejecutarIsListaDisponible() = 0;

        std::string toString();

};
#endif
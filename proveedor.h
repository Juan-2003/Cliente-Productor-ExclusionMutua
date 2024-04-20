#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

#include "entidad.hpp"

class Productor : public Entidad{
    public:
        Productor();
        void agregarElemento(char*);
        bool isListaDisponible() override;

};

#endif // PROVEEDOR_H_INCLUDED

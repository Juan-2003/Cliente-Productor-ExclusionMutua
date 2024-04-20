#ifndef PRODUCTOR_H_INCLUDED
#define PRODUCTOR_H_INCLUDED
#include "entidad.h"

class Productor : public Entidad{
    public:
        Productor();
        void ejecutarOperacion() override;
        bool ejecutarIsListaDisponible() override;
};
#endif // PRODUCTOR_H_INCLUDED

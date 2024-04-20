#ifndef CONSUMIDOR_H_INCLUDED
#define CONSUMIDOR_H_INCLUDED
#include "entidad.h"

class Consumidor : public Entidad{
    public:
        Consumidor();
        void ejecutarOperacion() override;
        bool ejecutarIsListaDisponible() override;
};

#endif // CONSUMIDOR_H_INCLUDED

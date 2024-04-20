#include "entidad.hpp"

#ifndef productor_HPP_INCLUDED
#define productor_HPP_INCLUDED

class Productor : public Entidad{
    public:
        Productor();
        void ejecutarOperacion() override;
        bool ejecutarIsListaDisponible() override;
};
#endif
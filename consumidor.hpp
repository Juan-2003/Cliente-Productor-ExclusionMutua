#include "entidad.hpp"

#ifndef consumidor_HPP_INCLUDED
#define consumidor_HPP_INCLUDED

class Consumidor : public Entidad{
    public:
        Consumidor();
        void ejecutarOperacion() override;
        bool ejecutarIsListaDisponible() override;
};
#endif  
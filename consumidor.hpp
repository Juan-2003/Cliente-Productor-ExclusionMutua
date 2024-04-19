#include "entidad.hpp"

#ifndef consumidor_HPP_INCLUDED
#define consumidor_HPP_INCLUDED

class Consumidor : public Entidad{
    public:
        Consumidor();
        void quitarElemento(char*);
        bool isListaDisponible() override;
};
#endif  
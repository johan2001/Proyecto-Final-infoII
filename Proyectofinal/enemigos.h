#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include "librerias.h"

class Enemigos : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Enemigos();
    void mover();

};

#endif // ENEMIGOS_H

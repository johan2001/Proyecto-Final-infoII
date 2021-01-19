#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H

#include <QWidget>
#include "librerias.h"

namespace Ui {
class Multijugador;
}

class Multijugador : public QWidget
{
    Q_OBJECT

public:
    explicit Multijugador(QWidget *parent = nullptr);
    ~Multijugador();

private:
    Ui::Multijugador *ui;
};

#endif // MULTIJUGADOR_H

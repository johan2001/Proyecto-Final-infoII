#ifndef OSTACULOS_H
#define OSTACULOS_H

#include <QWidget>
#include "librerias.h"

namespace Ui {
class Ostaculos;
}

class Ostaculos : public QWidget
{
    Q_OBJECT

public:
    explicit Ostaculos(QWidget *parent = nullptr);
    ~Ostaculos();

private:
    Ui::Ostaculos *ui;
};

#endif // OSTACULOS_H

#include "multijugador.h"
#include "ui_multijugador.h"

Multijugador::Multijugador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Multijugador)
{
    ui->setupUi(this);
}

Multijugador::~Multijugador()
{
    delete ui;
}

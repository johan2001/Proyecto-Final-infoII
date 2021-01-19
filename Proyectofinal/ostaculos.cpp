#include "ostaculos.h"
#include "ui_ostaculos.h"

Ostaculos::Ostaculos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ostaculos)
{
    ui->setupUi(this);
}

Ostaculos::~Ostaculos()
{
    delete ui;
}

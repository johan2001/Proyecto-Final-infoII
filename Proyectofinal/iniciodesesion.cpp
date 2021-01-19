#include "iniciodesesion.h"
#include "ui_iniciodesesion.h"

Iniciodesesion::Iniciodesesion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Iniciodesesion)
{
    ui->setupUi(this);
}

Iniciodesesion::~Iniciodesesion()
{
    delete ui;
}

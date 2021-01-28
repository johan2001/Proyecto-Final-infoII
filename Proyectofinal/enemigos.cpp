#include "enemigos.h"

Enemigos::Enemigos(int x, int y,QString direcion, QObject *parent): QObject(parent)
{

    Pos_X= x;
    Pos_Y= y;
    Direction = direcion;
    Ancho= 45;
    Alto= 65;
    tiempo = clock();
    if(Direction=="Derecha"){
        pixmap=new QPixmap(":/Personaje/Pesonaje/Enemigo Derecha.png");
    }
    else{
        pixmap=new QPixmap(":/Personaje/Pesonaje/Enemigo Izquierda.png");
    }


    TimerMover=new QTimer;
    connect(TimerMover,SIGNAL(timeout()),this,SLOT(Mover()));
    TimerMover->start(50);

    setPos(Pos_X,Pos_Y);


}
QRectF Enemigos::boundingRect() const
{
    return QRectF(0,0,Ancho,Alto); // se crea el rectangulo con su centro que son los primeros dos parametros y su ancho y alto
}

void Enemigos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect()); // Se pinta en el rectangulo usando el pixmap
    UNUSED(option);
    UNUSED(widget);
}

void Enemigos::Mover()
{
    if(Direction=="Derecha"){
        Pos_X += 5;
        setX(Pos_X);
    }
    if(Direction =="Izquierda"){
        Pos_X -= 5;
        setX(Pos_X);
    }
    if (int (clock() - tiempo) >= 5000){
        if(Direction=="Derecha"){
            Direction ="Izquierda";
            tiempo = clock();
            pixmap=new QPixmap(":/Personaje/Pesonaje/Enemigo Izquierda.png");
        }
        else {
            Direction ="Derecha" ;
            tiempo = clock();
            pixmap=new QPixmap(":/Personaje/Pesonaje/Enemigo Derecha.png");
        }
    }
}

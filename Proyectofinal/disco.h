#ifndef DISCO_H
#define DISCO_H

#include "librerias.h"

class Disco : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //atributos
    int Pos_X, Pos_Y;
    int Vel_X;
    int Alto, Ancho;
    int angulo;
    QString direction;
    QPixmap *pixmap;
    QTimer *timermove;
public:
    explicit Disco(int x, int y, QObject *parent = nullptr);

    //pinto la imaagen
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //metodos set
    int getVelX();
    int getWidth();
    QString getDirection();

    //metodos get
    void setVelX(int vel);
    void setDirection(QString direc);


signals:

public slots:

    //funciones para rotarlo y moverlo
    void moveRotation();
};


#endif // DISCO_H

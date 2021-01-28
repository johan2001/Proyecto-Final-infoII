#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include "librerias.h"

class Enemigos : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //atribustos principales
    int Pos_X;
    int Pos_Y;
    int Ancho;
    int Alto;
    QString Direction;
    //variables secundarias
    QTimer *TimerMover;
    QPixmap *pixmap;
    clock_t tiempo;
public:
    explicit Enemigos(int x, int y, QString direcion, QObject *parent = nullptr);
    // pinta el objeto
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:

public slots:
    void Mover();

};

#endif // ENEMIGOS_H

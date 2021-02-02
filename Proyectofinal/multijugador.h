#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H

#include <QWidget>
#include "librerias.h"
#include "jugador.h"
#include "disco.h"
#include "plataformas.h"
#include "enemigos.h"
#include "bullet.h"
#include "cuerda.h"
#include "jefe_final.h"
#include "findeljuego.h"
#include "winer.h"

namespace Ui {
class Multijugador;
}

class Multijugador : public QWidget
{
    Q_OBJECT

private:
    Ui::Multijugador *ui;
    //creacion de variables necearias
    int Pos_XJ=45, Pos_YJ=14,Pos_XP=0,Pos_YP=0;
    bool Balas = true ;
    int jefe_vida=1;
    Jugador *jugador;
    Jugador *jugador2;
    clock_t tiempo;
    Findeljuego *findeljuego;
    Winer *winer;


    QGraphicsScene *scene;
    QMap<int,bool> keys;

    //Matriz que armara el mapa(mundo)
    /* 0:
     * 1:cierras
     * 2:Piso
     * 3:Hueco
     * 4:Pared
     * 5:Tranpolin
     * 6:Mondea
     * 7:enemigos derecha
     * 8:enemigos Izquierda
     * 9:Door
     * 10:Rebote
     * 11:Pinchos
     * 12:Cuerda
     * 13:Jefe_Final
     *
     */
    short int mapa[15][90]=
    {
        {4,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,4   ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,4      ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,10,10,10,4},
        {4,0,0,0,0,0,0,0,0,0,4,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,4 ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2,3,0,0,0,0,0,0,0,0,0,0,0,4      ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4},
        {4,2,2,2,2,3,0,0,0,0,4,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,4   ,4,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,9      ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,0,4,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,4   ,4,0,0,10,0,0,0,0,0,0,0,10,10,0,0,0,0,0,0,0,10,0,0,0,1,0,0,0,10,0 ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,0,4,0,0,4,0,0,10,0,0,0,0,0,0,0,0,0,0,0,10,4 ,4,3,3,3,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4      ,4,2,2,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
        {4,0,0,3,2,2,2,2,2,2,4,0,0,4,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,4   ,4,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,4     ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,0,4,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4   ,4,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4      ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,13,0,0,4},
        {4,0,0,0,0,0,0,0,0,6,4,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,4   ,4,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,4      ,4,0,0,0,0,3,2,2,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
        {4,2,2,3,3,3,3,2,2,2,4,0,0,4,0,0,0,0,0,0,0,0,0,0,3,2,2,2,2,4   ,4,0,0,10,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,3,2,2,3,4    ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,0,4,0,0,4,0,0,0,0,0,0,0,3,2,3,0,0,0,0,0,4   ,4,3,3,2,2,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,3,0,0,0,0,0,4      ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,0,4,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4   ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4      ,4,2,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
        {4,0,0,3,2,2,2,2,2,2,4,0,0,4,0,0,0,3,2,2,2,3,0,0,0,0,0,0,0,4   ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,2,2,3,3,4      ,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9   ,4,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4      ,4,0,0,8,0,0,0,0,0,7,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0   ,4,0,0,10,0,0,0,0,0,10,0,0,10,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,10,4  ,4,10,0,0,0,0,10,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,4},
        {4,2,2,2,2,2,2,2,2,2,2,5,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4   ,4,2,2,2,2,2,2,2,2,2,11,11,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4    ,4,2,2,2,2,2,2,2,2,2,2,2,2,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4},


    };

    QTimer *timerColisiones;

    QList<Disco*> listDisco;
    QList<Plataformas*> listPlataformas;
    QList<Enemigos*> listEnemigos;
    QList<Bullet*> listBullet;
    QList<Cuerda*> ListCuerda;
    QList<Jefe_final*> ListJefe_final;



public:
    //Construtor de la clase
    explicit Multijugador(QWidget *parent = nullptr);
    //carturar el los eventos del teclado
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);
    //desctructor de la clase
    ~Multijugador();


public slots:
    //funcion que controlara todas las coliciones del juego
    void colisiones();

};

#endif // MULTIJUGADOR_H

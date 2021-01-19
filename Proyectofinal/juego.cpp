#include "juego.h"
#include "ui_juego.h"

Juego::Juego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Juego)
{
    ui->setupUi(this);

    //se incia el tiempo
    startTimer(2000/60);

    //creo un scena y la agrego a un graphicsView
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1200,600);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/Personaje/Fondo/BG.png").scaled(1200,600)); //Intoducir fondo

    //Recorre la matriz del mapa y agregas los objetos
    for (int i=0;i<15;i++) {
        for (int j=0;j<30;j++) {

             if(mapa[i][j]==1){
                 listDisco.push_back(new Disco(j*40,i*40));
                 scene->addItem(listDisco.last());
             }
        }
    }

    //creo un jugador y lo agrego a la ecena
    jugador=new Jugador(0,0); // le doy los valores de x y y
    scene->addItem(jugador);

    //Inici el tipo de la colociones
    timerColisiones=new QTimer;
    connect(timerColisiones,SIGNAL(timeout()),this,SLOT(colisiones()));
    timerColisiones->start(1);

}
Juego::~Juego()
{
   delete ui;
}

void Juego::keyPressEvent(QKeyEvent *event)
    {
    keys[event->key()]=true; QWidget::keyPressEvent(event);
    }


void Juego::keyReleaseEvent(QKeyEvent *event)
    {
    keys[event->key()]=false; QWidget::keyReleaseEvent(event);
    }


void Juego::timerEvent(QTimerEvent *)
{
    if(keys[Qt::Key_A]){
        jugador->Mover_iz();
    }

    if(keys[Qt::Key_D]){
        jugador->Mover_De();
    }
    if(keys[Qt::Key_Space]){
         jugador->salto();

    }
}
void Juego::colisiones()
{

}



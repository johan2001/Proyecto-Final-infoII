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
    scene->setSceneRect(0,0,3600,600);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/Personaje/Fondo/BG.png").scaled(1200,600)); //Intoducir fondo

    //Recorre la matriz del mapa y agregas los objetos
    for (int i=0;i<15;i++) {
        for (int j=0;j<90;j++) {

             if(mapa[i][j]==1){
                 listDisco.push_back(new Disco(j*40,i*40));
                 scene->addItem(listDisco.last());
             }
             if(mapa[i][j]==2){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Piso"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==3){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Hueco"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==4){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Pared"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==5){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Tranpolin"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==6){
                 listPlataformas.push_back(new Plataformas(j*40,i*40,"Moneda"));
                 scene->addItem(listPlataformas.last());
             }
             if(mapa[i][j]==7){
                 listEnemigos.push_back(new Enemigos(j*40,i*40+20,"Derecha"));
                 scene->addItem(listEnemigos.last());
             }
             if(mapa[i][j]==8){
                 listEnemigos.push_back(new Enemigos(j*40,i*40+20,"Izquierda"));
                 scene->addItem(listEnemigos.last());
             }

        }
    }

    //creo un jugador y lo agrego a la ecena
    jugador=new Jugador(45,14); // le doy los valores de x y y
    scene->addItem(jugador);

    ListdeVidas.push_back(new Vidas(1100,20));
    scene->addItem(ListdeVidas.last());
    ListdeVidas.push_back(new Vidas(1050,20));
    scene->addItem(ListdeVidas.last());
    ListdeVidas.push_back(new Vidas(1000,20));
    scene->addItem(ListdeVidas.last());

    puntaje = new Puntaje();
    puntaje->setPos(puntaje->x(),puntaje->y()+10);
    scene->addItem(puntaje);

    //Inici el tipo de la colociones
    timerColisiones=new QTimer;
    connect(timerColisiones,SIGNAL(timeout()),this,SLOT(colisiones()));
    timerColisiones->start(0);

}
Juego::~Juego()
{
    delete ui;
    delete timerColisiones;
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
    if (Balas ){
        if(keys[Qt::Key_F]){
            if(jugador->getDireccion()=="derecha"){
                listBullet.push_back(new Bullet(jugador->getPos_X()+jugador->getAncho(),jugador->getPos_Y()+jugador->getAlto()/2,jugador->getDireccion()));
            }
            if(jugador->getDireccion()=="izquierda"){
                listBullet.push_back(new Bullet(jugador->getPos_X(),jugador->getPos_Y()+jugador->getAlto()/2,jugador->getDireccion()));
            }

            scene->addItem(listBullet.last());
            Balas = false;
        }
    }
    else {
        if(keys[Qt::Key_R]){
            Balas = true;
        }
    }

    if(keys[Qt::Key_A]){
        jugador->Mover_iz();
        jugador->Animacion_Run_Izquierda();
    }

    if(keys[Qt::Key_D]){
        jugador->Mover_De();
        jugador->Animacion_Run_Derecha();
    }
    if(keys[Qt::Key_Space]){
         jugador->salto();

    }
}
void Juego::colisiones()
{
    for(int i=0;i<listPlataformas.size();i++){
        listPlataformas.at(i)->Actualizar_Pos_Per(jugador);
        if(listPlataformas.at(i)->getClase() == "Moneda" && listPlataformas.at(i)->collidesWithItem(jugador)){
            puntaje->Aumentarpuntaje(100);
            scene->removeItem(listPlataformas.at(i));
            listPlataformas.removeAt(i);
        }
        for(int j=0;j<listBullet.size();j++){
            if(listPlataformas.at(i)->getClase() == "Pared" && listPlataformas.at(i)->collidesWithItem(listBullet.at(j))){
            scene->removeItem(listBullet.at(j));
            listBullet.removeAt(j);
            }
        }
    }
   for(int i=0;i<listEnemigos.size();i++){
       for (int j=0;j<listBullet.size();j++) {
           if (listBullet.at(j)->collidesWithItem(listEnemigos.at(i))){
                listEnemigos.at(i)->setPos(-100,-100);
                scene->removeItem(listEnemigos.at(i));
                scene->removeItem(listBullet.at(j));
                listBullet.removeAt(j);
                puntaje->Aumentarpuntaje(25);
           }

       }
       if (jugador->collidesWithItem(listEnemigos.at(i))){
           jugador->setX(45);
           jugador->set_X(45);
           jugador->set_Y(14);
           jugador->setY(14);
           scene->removeItem(ListdeVidas.at(0));
           ListdeVidas.removeAt(0);

       }
   }

}



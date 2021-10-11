#include "mainWindow.h"

mainWindow::mainWindow(QWidget *parent)
{
    scene = new QGraphicsScene();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1700,900);

    scene->setSceneRect(0,0,1700,900);
    setScene(scene);
    starterMenu();
}
void mainWindow::starterMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("3dRendering"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("Start"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(make()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void mainWindow::draw()
{
    scene->clear();
    int loc;
    for(int i=0;i<list.size();i++)
    {
        loc=(1600*i/list.size())+50;
        QGraphicsLineItem* Line= new QGraphicsLineItem(loc,700,loc,700-*list[i]);
        scene->addItem(Line);
    }

}
void mainWindow::make()
{
    scene->clear();
    int* nr;
    QRandomGenerator* random = new QRandomGenerator();
    for(int i=0;i<20000;i++)
    {
        nr= new int(random->bounded(0,500));
        list.append(nr);
    }

    sorter* sort=new sorter(scene,list);
    sort->moveToThread(&sortingThread);
    connect(&sortingThread, &QThread::finished, sort, &QObject::deleteLater);
    connect(this, &mainWindow::operate, sort, &sorter::BubbleSort);
    connect(sort, &sorter::draw, this, &mainWindow::draw);
    sortingThread.start();
    emit operate();
}

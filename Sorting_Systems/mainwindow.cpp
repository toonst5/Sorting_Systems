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
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Sorting systems"));
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

void mainWindow::draw(int i)
{
    //scene->clear();
    int size=list.size();
    lines[i]->setLine((1600*i/size)+50,700,(1600*i/size)+50,700-*list[i]);
    i++;
    lines[i]->setLine((1600*i/size)+50,700,(1600*i/size)+50,700-*list[i]);
}
void mainWindow::make()
{
    scene->clear();
    int* nr;
    int size=2000;
    QRandomGenerator* random = new QRandomGenerator();
    for(int i=0;i<size;i++)
    {
        nr= new int(random->bounded(0,500));
        list.append(nr);
        lines.append(new QGraphicsLineItem((1600*i/size)+50,700,(1600*i/size)+50,700-*nr));
        scene->addItem(lines[i]);
    }

    sorter* sort=new sorter(list,lines);
    sort->moveToThread(&sortingThread);
    connect(&sortingThread, &QThread::finished, sort, &QObject::deleteLater);
    connect(this, &mainWindow::operate, sort, &sorter::original);
    connect(sort, &sorter::draw, this, &mainWindow::draw);
    sortingThread.start();
    emit operate();
}

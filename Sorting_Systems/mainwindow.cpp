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
    if(i>=0)
    {
        int size=list.size();
        lines[i]->setLine((1600*i/size)+50,700,(1600*i/size)+50,700-*list[i]);
        i++;
        lines[i]->setLine((1600*i/size)+50,700,(1600*i/size)+50,700-*list[i]);
    }else
    {
        for(int x=0;x<list.size();x++)
        {
            int size=list.size();
            lines[x]->setLine((1600*x/size)+50,700,(1600*x/size)+50,700-*list[x]);
        }
    }

}

void mainWindow::make()
{
    scene->clear();
    int* nr;
    int size=100000;
    QRandomGenerator* random = new QRandomGenerator();
    for(int i=0;i<size;i++)
    {
        nr= new int(random->bounded(0,500));
        list.append(nr);
        lines.append(new QGraphicsLineItem((1600*i/size)+50,700,(1600*i/size)+50,700-*nr));
        scene->addItem(lines[i]);
    }

    Button* playButton = new Button(QString("Start"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 50;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(sortStart()));
    scene->addItem(playButton);
}

void mainWindow::sortStart()
{
    bucketSort* sort=new bucketSort(list);
    connect(sort, &bucketSort::drawB, this, &mainWindow::draw);
    sort->sort();
}

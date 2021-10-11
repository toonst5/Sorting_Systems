#ifndef SORTER_H
#define SORTER_H

#include <QList>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QThread>

class sorter: public QObject
{
    Q_OBJECT
private:
    QList<int*>* list;
    QGraphicsScene* cene;
public:
    sorter(QGraphicsScene*ceneO,QList<int*>&listO){cene=ceneO;list=&listO;}
    sorter();
public slots:
    void BubbleSort();
    void original();
    //void bucketSort();
signals:
    void draw();
};

#endif // SORTER_H

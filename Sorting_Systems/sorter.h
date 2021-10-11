#ifndef SORTER_H
#define SORTER_H

#include <QList>
#include <QThread>
#include <QGraphicsRectItem>

class sorter: public QObject
{
    Q_OBJECT
private:
    QList<int*>* list;
    QList<QGraphicsLineItem*>* lines;
public:
    sorter(QList<int*>&listO,QList<QGraphicsLineItem*>& linesO){list=&listO;lines=&linesO;}
    sorter();
public slots:
    void BubbleSort();
    void original();
    //void bucketSort();
signals:
    void draw(int);
};

#endif // SORTER_H

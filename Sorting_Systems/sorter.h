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
public:
    sorter(QList<int*>&listO){list=&listO;}
    sorter();
public slots:
    void BubbleSort();
    void original();
    //void bucketSort();
signals:
    void draw(int);
    void done();
};

#endif // SORTER_H

#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <QList>
#include <QThread>
#include "sorter.h"

class bucketSort: public QObject
{
    Q_OBJECT
private:
    QList<int*>* list;

    int doneC;
    QList<QList<int*>*> bath;
    void fill();
public:
    bucketSort(QList<int*>&listO){list=&listO;}
    void sort();
public slots:
    void draw(int);
    void done();
signals:
    void operate();
    void drawB(int);
};

#endif // BUCKETSORT_H

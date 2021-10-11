#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <QList>
#include <QThread>

class bucketSort: public QObject
{
    Q_OBJECT
private:
    QList<int*>* list;
public:
    bucketSort(QList<int*>&listO){list=&listO;}
public slots:
    void sort();
signals:
    void draw();
};

#endif // BUCKETSORT_H

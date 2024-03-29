#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "sorter.h"
#include <QRandomGenerator>
#include "button.h"
#include "bucketsort.h"

class mainWindow: public QGraphicsView
{
    Q_OBJECT
    QThread sortingThread;
private:
    QGraphicsScene* scene;
    QList<int*> list;
    void starterMenu();
    QList<QGraphicsLineItem*> lines;
public:
    mainWindow(QWidget* parent=NULL);
public slots:
    void make();
    void draw(int);
    void sortStart();
signals:
    void operate();

};

#endif // MAINWINDOW_H

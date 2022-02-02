#ifndef SORTER_H
#define SORTER_H

#include <QList>
#include <QThread>
#include <QGraphicsRectItem>

class sorter: public QObject
{
    Q_OBJECT
private:
    struct Node
    {
        int key;
        struct Node *left, *right;
    };

    struct Node *newNode(int item)
    {
        struct Node *temp = new Node;
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
    }

    QList<int*>* list;
    void BubbleSort();
    void original();
    void swap(int, int);
    int partition(int , int );
    void quickSort(int , int );
    void insertionSort(int n);
    void compAndSwap(int, int, int);
    void bitonicMerge(int,int,int);
    void bitonicSort(int , int , int);
    void sortBitonicSort(int, int );
    void heapify(int, int);
    void heapSort(int);
    void storeSorted(Node*,int&);
    Node* insert(Node* , int );
    void treeSort(int);
public:
    sorter(QList<int*>&listO){list=&listO;}
    sorter();
public slots:
    void quickSortStart(){this->quickSort(0,list->size()-1);emit done();this->thread()->exit();}
    void insertionSortStart(){this->insertionSort(list->size());emit done();this->thread()->exit();}
    void bitonicSortStart(){this->sortBitonicSort(list->size(),1);emit done();this->thread()->exit();}
    void heapSortStart(){this->heapSort(list->size());emit done();this->thread()->exit();}
    void treeSortStart(){this->treeSort(list->size());emit done();this->thread()->exit();}
signals:
    void draw(int);
    void done();
};

#endif // SORTER_H

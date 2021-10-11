#include "bucketsort.h"

void bucketSort::sort()
{
    doneC=0;
    int place=0;
    QList<int*>* bucket;
    QList<QThread*> threads;
    QList<sorter*> sorters;
    for(int y=0;y<50;y++)
    {
        bucket=new QList<int*>;
        bath.append(bucket);
    }

    for(int i=0;i<list->size();i++)
    {
        while(*(*list)[i]>place*10)
        {
            place++;
            if(place>49)
            {
                place=49;
                break;
            }
        }
        bath[place]->append((*list)[i]);
        place=0;
    }
    sorter* srt;
    QThread* sortingThread;
    for(int i=0;i<(bath.size()-1);i++)
    {
        srt=new sorter(*bath[i]);
        sortingThread=new QThread();
        srt->moveToThread(sortingThread);
        connect(sortingThread, &QThread::finished, srt, &QObject::deleteLater);
        connect(this, &bucketSort::operate, srt, &sorter::original);
        //connect(srt, &sorter::draw, this, &bucketSort::draw);
        connect(srt, &sorter::done, this, &bucketSort::done);
        sortingThread->start();
        sorters.append(srt);
        threads.append(sortingThread);
    }
    emit operate();
}

void bucketSort::draw(int i)
{
    emit drawB(i);
}

void bucketSort::done()
{
    doneC++;
    if(doneC==bath.size()-1)
    {
        fill();
    }
}

void bucketSort::fill()
{
    int x=0;
    for(int i=0;i<bath.size();i++)
    {
        for(int y=0;y<(*bath[i]).size();y++)
        {
            list[x]=bath[i][y];
            x++;
        }
    }
    emit drawB(-1);
}

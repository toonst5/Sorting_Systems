#include "bucketsort.h"

void bucketSort::sort()
{
    int place=0;
    QList<QList<int*>*> bath;
    QList<int*>* bucket;
    for(int y=0;y<50;y++)
    {
        bucket=new QList<int*>;
        bath.append(bucket);
    }

    for(int i=0;i<list->size();i++)
    {
        while(*(*list)[i]<place*10)
        {
            place++;
            if(place>50)
            {
                place=50;
                break;
            }
        }
        bath[place]->append((*list)[i]);
        place=0;
    }
    sorter* srt;
    for(int i=0;i<bath.size();i++)
    {
        srt=new sorter(*list,*lines);
    }
}

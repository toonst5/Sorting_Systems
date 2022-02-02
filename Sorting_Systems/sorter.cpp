#include "sorter.h"

void sorter::BubbleSort()
{
    int* temp;
    int i, j;
    int n=(*list).size();
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (*(*list)[j] < *(*list)[j+1])
            {
                temp=(*list)[j];
                (*list)[j]=(*list)[j+1];
                (*list)[j+1]=temp;
                emit draw(j);
                for(int w=0;w<15000;w++)
                {
                    w++;
                }
            }
        }
    }
    emit done();
    this->thread()->exit();
}

void sorter::original()
{
    for(int i=0;(i<(*list).size()-1);i++)
    {
        if(*(*list)[i] <*(*list)[i+1])
        {
            (*list).move(i,i+1);
            emit draw(i);
            i=0;
        }
    }
    emit done();
    this->thread()->exit();
}

void sorter::swap(int a, int b)
{
    int* temp;
    temp=(*list)[a];
    (*list)[a]=(*list)[b];
    (*list)[b]=temp;
}

int sorter::partition (int low, int high)
{
    int pivot = *(*list)[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (*(*list)[j] >= pivot)
        {
            i++;
            swap(i, j);
        }
    }
    swap((i + 1), high);
    return (i + 1);
}

void sorter::quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = this->partition(low, high);
        this->quickSort(low, pi - 1);
        this->quickSort(pi + 1, high);
    }
}

void sorter::insertionSort(int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = *(*list)[i];
        j = i - 1;
        while (j >= 0 && *(*list)[j] < key)
        {
            *(*list)[j+1] = *(*list)[j];
            j = j - 1;
        }
        *(*list)[j+1] = key;
    }
}

void sorter::compAndSwap(int i, int j, int dir)
{
    if (dir==(*(*list)[i]<*(*list)[j]))
        swap(i,j);
}

void sorter::bitonicMerge(int low, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;
        for (int i=low; i<low+k; i++)
            compAndSwap(i, i+k, dir);
        bitonicMerge(low, k, dir);
        bitonicMerge(low+k, k, dir);
    }
}

void sorter::bitonicSort(int low, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;

        bitonicSort(low, k, 1);

        bitonicSort(low+k, k, 0);

        bitonicMerge(low, cnt, dir);
    }
}

void sorter::sortBitonicSort(int N, int up)
{
    bitonicSort(0, N, up);
}

void sorter::heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && *(*list)[l] < *(*list)[largest])
        largest = l;

    if (r < n && *(*list)[r] < *(*list)[largest])
        largest = r;

    if (largest != i) {
        swap(i, largest);
        heapify(n, largest);
    }
}

void sorter::heapSort(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(0, i);
        heapify(i, 0);
    }
}

void sorter::storeSorted(Node *root, int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, i);
        *(*list)[i++] = root->key;
        storeSorted(root->right, i);
    }
}


sorter::Node* sorter::insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void sorter::treeSort(int n)
{
    struct Node *root = NULL;
    root = insert(root, 0);
    for (int i=1; i<n; i++)
        root = insert(root, i);

    int i = 0;
    storeSorted(root, i);
}

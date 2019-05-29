#include "minheap.h"
minheap::minheap(int sz)
{
    maxheapsize = (defaultsize < sz)?sz:defaultsize;
    heap = new int[maxheapsize];
    currentsize = 0;
}
minheap::minheap(int* arr,int n)
{
    maxheapsize = (defaultsize < n)?n:defaultsize;
    heap = new int[maxheapsize];
    if(heap == NULL) cout <<"error";
    for(int i = 0;i < n;i++)
        heap[i] = arr[i];
    currentsize = n;
    int currentpos = (currentsize - 2) / 2;
    while(currentpos >= 0)
    {
        siftdown(currentpos,currentsize-1);
        currentpos--;
    }
}
void minheap::siftdown(int start,int m)
{
    int i = start,j = 2*i + 1;
    int temp  = heap[i];
    while(j <= m)
    {
        if(j < m && heap[j] > heap[j+1]) j++;
        if(temp <= heap[j]) break;
        else
        {
            heap[i] = heap[j];
            i = j;
            j = 2*j + 1;
        }
    }
    heap[i] = temp;
}
void minheap::display()
{
    for(int i = 0;i < currentsize;i++)
    {
        cout <<"���ڵ�:"<<heap[i]<<" ";
        if(2*i + 1 < currentsize)  cout <<"����:"<<heap[2*i + 1]<<" ";
        else cout <<"NULL"<<" ";
        if(2*i + 2 < currentsize) cout <<"�Һ���:"<<heap[2*i + 2];
        else cout <<"NULL";
        cout <<endl;
    }
}
void minheap::siftup(int start)
{
    int j = start;
    int        i = (j - 1)/2;
    int temp = heap[j];
    while(j > 0)
    {
        if(heap[i] <= temp) break;
        else
        {
            heap[j] = heap[i];
            j = i;
            i = (i - 1)/2;
        }
    }
    heap[j] = temp;
}
bool minheap::Insert(const int& x)
{
    if(currentsize == maxheapsize)
    {
        cout <<"heap full"<<endl;
        return false;
    }
    heap[currentsize] = x;
    siftup(currentsize);
    currentsize++;
    return true;
}
bool minheap::Removemin(int& x)
{
    if(!currentsize)
    {
        cout <<"heap empty"<<endl;
        return false;
    }
    x = heap[0];
    heap[0] = heap[currentsize - 1];
    currentsize--;
    siftdown(0,currentsize-1);
    return true;
}

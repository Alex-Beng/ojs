#include <iostream>
using namespace std;
#define defaultsize 10

class minheap
{
public:
    minheap(int sz = defaultsize);
    minheap(int* arr,int n);
    ~minheap(){delete []heap;}
    bool Insert(const int& x);
    bool Removemin(int& x);
    bool isempty()
    {
        return (currentsize == 0)?true:false;
    }
    bool isfull()
    {
        return (currentsize == maxheapsize)?true:false;
    }
    void makeempty(){currentsize = 0;}
    void display();
private:
    int* heap;
    int currentsize;
    int maxheapsize;
    void siftdown(int start,int m);
    void siftup(int start);
};

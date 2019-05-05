#include <iostream>
#include "minheap.h"
using namespace std;

int main()
{
    //int test[] = {9,23,78,45,87,53,31,17,65};

    minheap t;
    t.Insert(9);
    t.Insert(23);
    t.Insert(78);
    t.Insert(45);
    t.Insert(87);
    t.Insert(53);
    t.Insert(31);
    t.Insert(17);
    t.Insert(65);
    t.display();
    return 0;
}

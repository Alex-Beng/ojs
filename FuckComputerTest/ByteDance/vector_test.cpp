#include <iostream>
#include <list>
#include <vector>
#include <cstring>
using namespace std;

class B
{
public:
    B()
    {
        cout<<"B()"<<endl;
    }
    void print()
    {
        cout<<"print"<<endl;
        p = NULL;
        len = 0;
    }
    B(const B& b)
    {
        cout<<"copy B()"<<endl;
        if(p != NULL)
        {
            delete b.p;
            len = len;
            p = new char[len];
            memcpy(p, b.p, len);
        }
    }

    char *p;
    int len;

};

int main()
{
    
    list<B> ls;
    vector<B> vec;
    B b;
    ls.push_back(b);
    vec.push_back(b);
    return 0;
}
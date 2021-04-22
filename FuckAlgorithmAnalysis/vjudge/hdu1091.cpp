#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    while (cin>>a>>b) {
        if ((a|b) == 0) break;//!
        cout<<a+b<<endl;
    }
    
    return 0;
}
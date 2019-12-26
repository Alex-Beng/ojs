#include <iostream>
using namespace std;

void ToTwo(int n) {
    if (n == 1) {
        cout<<n;
    }
    else {
        int t = n%2;
        ToTwo(n/2);
        cout<<t;
    }
}


int main(int argc, char const *argv[]) {
    int n;
    while (cin>>n) {
        ToTwo(n);
        cout<<endl;
    }
    
    return 0;
}
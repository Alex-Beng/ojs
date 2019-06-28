#include <iostream>
using namespace std;

int FindRoot(int t) {
    int root = 0;
    while (1) {
        root += t%10;
        t /= 10;
        if (t==0) {
            break;
        }
    }
    return root;
}

int main() {
    int t;
    cin>>t;
    while (t>=10) {
        t = FindRoot(t);
    }
    cout<<t<<endl;
    return 0;
}
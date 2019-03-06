#include <iostream>
using namespace std;
void take_apart(int n) {
    if (n == 0) {
        return ;
    }
    else {
        int t = n%10;
        take_apart(n/10);
        cout<<t<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    take_apart(t);
}
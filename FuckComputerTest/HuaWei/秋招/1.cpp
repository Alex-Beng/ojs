#include <iostream>
using namespace std;

int getSum(int n) {
    if (n<10) {
        return n;
    }
    else {
        return n%10+getSum(n/10);
    }
}

int main(int argc, char const *argv[]) {
    int n, m;
    cin>>n>>m;

    cout<<getSum(n)%getSum(m)<<endl;
    return 0;
}
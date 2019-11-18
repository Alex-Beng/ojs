#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b, c;
    cin>>a>>b>>c;
    for (int i=1; i<=105; i++) {
        if (i%3==a && i%5==b && i%7==c) {
            cout<<i<<endl;
        }
    }
    return 0;
}
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    for (int i=1; i<=105; i++) {
        if (i%3==2 && i%5==1 && i%7==4) {
            cout<<i<<endl;
        }
    }
    return 0;
}
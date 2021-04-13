#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    double ya;
    while (cin>>ya) {
        if (ya<0) ya = -ya;
        printf("%.2f\n", ya);
    }
    return 0;
}
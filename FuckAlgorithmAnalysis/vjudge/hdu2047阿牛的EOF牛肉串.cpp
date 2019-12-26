#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long int O[66];// O(n) 以O结尾的字符串
    long long int T[66];// T(n) 不以O结尾的字符串
    long long int F[66];// F(n) ans
    O[1] = 1;
    T[1] = 2;
    F[1] = 3;
    for (int i=2; i<55; i++) {
        O[i] = T[i-1];
        T[i] = F[i-1];
        F[i] = 2*O[i-1] + 3*T[i-1];
    }
    int n;
    while (cin>>n) {
        cout<<F[n]<<endl;
    }
    
    return 0;
}
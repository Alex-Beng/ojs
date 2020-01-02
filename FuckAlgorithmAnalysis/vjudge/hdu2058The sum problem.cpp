#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    while (cin>>n>>m) {
        if (n==0 && m==0) {
            break;
        }
        // [a1, an] d=1连续等差数列和
        // 结果区间为[a1, a1+n]
        // m = a1*n + (n-1)*n/2, 即 m = f(a1, n)
        // 可化成 a1*n = m - (n-1)*n/2
        // a1∈[1, ] => n∈[0, √(2m)]
        // 即枚举n, 计算a1, 

        for (int nn = sqrt(2.0*m); nn >= 1; nn--) {
            int a1n = m - (nn-1)*nn/2;
            if (a1n%nn == 0) {
                cout<<'['<<a1n/nn<<','<<a1n/nn+nn-1<<']'<<endl;
            }
        }
        cout<<endl;
    }   
    
    return 0;
}
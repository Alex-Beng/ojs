#include <iostream>
using namespace std;

// 得到Cm,n
long long int C(int m, int n) {
    if (m<n || n<0) {
        return 0;
    }
    if (m==n || n==0) {
        return 1;
    }
    return C(m-1, n-1)+C(m-1, n);
}

int main(int argc, char const *argv[]) {
    long long int ans[66];
    ans[2] = 1;
    ans[3] = 2;
    for (int i=4; i<55; i++) {
        ans[i] = (i-1)*(ans[i-1] + ans[i-2]);
    }
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int M, N;
        cin>>M>>N;
        cout<<C(M, N)*ans[N]<<endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long int ans[66];
    ans[1] = 3;
    ans[2] = 6;
    ans[3] = 6;
    for (int i=4; i<55; i++) {// 注意1 2 3不符合这个规律233
        ans[i] = ans[i-1] + ans[i-2]*2;
    }
    int n;
    while (cin>>n) {
        cout<<ans[n]<<endl;
    }
    
    return 0;
}
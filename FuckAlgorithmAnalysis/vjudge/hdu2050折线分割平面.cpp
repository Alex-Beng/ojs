#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long int ans[23333];
    ans[1] = 2;
    ans[2] = 7;
    for (int i=3; i<20000; i++) {
        ans[i] = ans[i-1] + 4*(i-1) + 1;
    }
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int t;
        cin>>t;
        cout<<ans[t]<<endl;
    }
    return 0;
}
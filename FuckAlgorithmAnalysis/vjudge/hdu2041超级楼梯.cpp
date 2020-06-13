#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long int ans[50];
    ans[2] = 1;
    ans[3] = 2;
    for (int i=4; i<50; i++) {
        ans[i] = ans[i-1] + ans[i-2];
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
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long int ans[66]; // 注意long long
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int b, e;
        cin>>b>>e;
        ans[b] = 0;
        ans[b+1] = 1;
        ans[b+2] = 2;
        for (int j=b+3; j<=e; j++) {
            ans[j] = ans[j-1] + ans[j-2];
        }
        cout<<ans[e]<<endl;
    }
    return 0;
}
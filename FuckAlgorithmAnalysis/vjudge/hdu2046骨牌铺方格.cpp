#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long int ans[66];
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    for (int i=4; i<55; i++) {
        ans[i] = ans[i-1] + ans[i-2];
    }
    int n;
    while (cin>>n) {
        cout<<ans[n]<<endl;
    }
    
    return 0;
}
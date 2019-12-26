#include <iostream>
using namespace std;

inline int reverse(int n) {
    return (n-1)*2;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        cin>>a;
        int ans = 3;
        for (int j=0; j<a; j++) {
            ans = reverse(ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
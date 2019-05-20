#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    int k;
    int t;
    cin>>n>>k;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    for (int i=0; i<k; i++) {
        t = a[n-1];
        for (int j=n-2; j>=0; j--) {
            a[j+1] = a[j];
        }
        a[0] = t;
    }
    for (int i=0; i<n; i++) {
        cout<<a[i];
        if (i != n-1) {
            cout<<' ';
        }
    }
    return 0;
}

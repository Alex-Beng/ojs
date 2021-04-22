#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int t, sum=0, tt;
        cin>>t;
        for (int j=0; j<t; j++) {
            cin>>tt;
            sum += tt;
        }
        cout<<sum<<endl;

    }
    return 0;
}
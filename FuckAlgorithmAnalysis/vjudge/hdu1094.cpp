#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    while (cin>>n) {
        int t, sum=0;
        for (int j=0; j<n; j++) {
            cin>>t;
            sum += t;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}
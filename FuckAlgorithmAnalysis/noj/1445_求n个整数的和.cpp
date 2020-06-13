#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int t, sum=0;
    for (int i=0; i<n; i++) {
        cin>>t;
        sum += t;
    }
    cout<<sum<<endl;
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n;
    int shift;
    cin>>n>>shift;
    shift = shift%n;
    int nums[n];
    for (int i=0; i<n; i++) {
        cin>>nums[i];
    }
    
    for (int i=n-shift; i%n != n-shift-1; i++) {
        cout<<nums[i%n]<<' ';
        // cout<<i<<endl;
    }
    cout<<nums[n-shift-1];
    return 0;
}
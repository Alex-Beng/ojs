#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
    int n;
    int k;
    int t;
    cin>>n;
    int nums[n];
    for (int i=0; i<n; i++) {
        cin>>nums[i];
    }

    cin>>k;
    k %= n;
    for (int i=0; i<k; i++) {
        t = nums[n-1];
        for (int i=n-1; i>=1; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = t;
    }
    for (int i=0; i<n; i++) {
        cout<<nums[i]<<endl;
    }
    
    return 0;
}

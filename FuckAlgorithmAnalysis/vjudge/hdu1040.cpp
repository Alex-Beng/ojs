#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, nums[2333], t;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>t;
        for (int j=0; j<t; j++) {
            cin>>nums[j];
        }
        std::sort(nums, nums+t);
        for (int j=0; j<t; j++) {
            cout<<nums[j];
            if (j!=t-1) cout<<' ';
        }
        // if (i!=n-1) cout<<endl;
        cout<<endl;
    }
    return 0;
}
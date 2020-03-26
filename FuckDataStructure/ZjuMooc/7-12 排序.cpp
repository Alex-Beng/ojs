#include <iostream>
#include <algorithm>
using namespace std;

int n;
int nums[100001];

int main(int argc, char const *argv[]) {
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>nums[i];
    }
    std::sort(nums, nums+n);
    for (int i=0; i<n; i++) {
        cout<<nums[i];
        if (i!=n-1) {
            cout<<' ';
        }
    }
    cout<<endl;

    return 0;
}
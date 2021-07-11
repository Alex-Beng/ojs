#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long nums[233333];
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>nums[i];
    }
    std::sort(nums, nums+n);
    int ans = 0;
    for (int i=1; i<n; i++) {
        if (nums[i-1] == nums[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
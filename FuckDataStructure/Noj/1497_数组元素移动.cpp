#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
    int n;
    int k;
    cin>>n;
    int nums[n];
    for (int i=0; i<n; i++) {
        cin>>nums[i];
    }

    cin>>k;
    k %= n;
    
    return 0;
}

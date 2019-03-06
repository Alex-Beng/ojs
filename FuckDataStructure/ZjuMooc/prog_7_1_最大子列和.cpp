#include <iostream>
using namespace std;

int main() {
    int n;
    int t;
    cin>>n;
    long long max_sub_sum = 0;
    long long now_sub_sum = 0;

    for (int i=0; i<n; i++) {
        cin>>t;
        now_sub_sum += t;
        if (now_sub_sum < 0) {
            now_sub_sum = 0;
        }
        if (now_sub_sum > max_sub_sum) {
            max_sub_sum = now_sub_sum;
        }
    }
    cout<<max_sub_sum;
    return 0;
}
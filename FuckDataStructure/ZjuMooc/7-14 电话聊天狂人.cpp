#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    long long t1, t2;
    std::unordered_map<long long , int> times;
    for (int i=0; i<n; i++) {
        cin>>t1>>t2;
        if (times.count(t1)) {
            times[t1]++;
        }
        else {
            times[t1] = 1;
        }

        if (times.count(t2)) {
            times[t2]++;
        }
        else {
            times[t2] = 1;
        }
    }
    int max = -1;
    long long ans = -1;
    for (auto& time : times) {
        // cout<<time.first<<endl;
        if (time.second > max) {
            max = time.second;
            ans = time.first;
        }
        else if (time.second == max) {
            if (time.first < ans) {
                ans = time.first;
            }
        }
    }
    cout<<ans<<' '<<max;

    int cnt = 0;
    for (auto& time : times) {
        if (time.second == max) {
            cnt++;
        }
    }
    if (cnt > 1) {
        cout<<' '<<cnt;
    }
    cout<<endl;
    return 0;
}
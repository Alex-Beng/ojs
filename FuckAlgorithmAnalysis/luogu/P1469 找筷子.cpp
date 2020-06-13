#include <map>
#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    // 别问，问就是cin tle
    int n;
    int t; 
    int ans = 0;
    cin>>n;
    for (int i=0; i<n; i++) {
        // cin>>t;
        scanf("%d", &t);
        ans ^= t;
    }
    cout<<ans<<endl;
    // 别问，问就是红黑树tle
    // std::map<int, int> id2num;
    // int n;
    // int t;
    // cin>>n;
    // for (int i=0; i<n; i++) {
    //     cin>>t;
    //     if (id2num[t] == 0) {
    //         id2num[t] = 1;
    //     }
    //     else {
    //         id2num[t] = 0;
    //     }
    // }
    // for (auto i=id2num.begin(); i!=id2num.end(); i++) {
    //     if (i->second) {
    //         cout<<i->first<<endl;
    //     }
    // }
    return 0;
}
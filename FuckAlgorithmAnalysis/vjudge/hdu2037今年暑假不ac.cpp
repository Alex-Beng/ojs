// #define DEBUG
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


struct program {
    int begin_time;
    int end_time;
};

bool for_sort(program p1, program p2) {
    return p1.end_time<p2.end_time;
}


int main(int argc, char const *argv[]) {
    int n;
    
    while (cin>>n && n) {
        vector<program> pgs;
        for (int i=0; i<n; i++) {
            program t;
            cin>>t.begin_time>>t.end_time;
            pgs.push_back(t);
        }
        sort(pgs.begin(), pgs.end(), for_sort);
#ifdef DEBUG
        for (unsigned int i=0; i<pgs.size(); i++) {
            cout<<pgs[i].begin_time<<' '<<pgs[i].end_time<<endl;
        }
#endif  
        // get ans
        int ans = 0;
        int t_end = -1;
        for (unsigned int i=0; i<pgs.size(); i++) {
            if (pgs[i].begin_time >= t_end) {
                t_end = pgs[i].end_time;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

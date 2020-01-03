#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int l;
    int n, c, t;
    int vr, vt1, vt2;
    while (cin>>l) {
        cin>>n>>c>>t;
        cin>>vr>>vt1>>vt2;
        int ps[n+2];
        double dp[n+2];
        // 起点和终点看成两个充电站
        // dp[i]为到这个终点站最短用时
        ps[0] = 0;
        dp[0] = 99999999;
        for (int i=1; i<=n; i++) {
            cin>>ps[i];
            dp[i] = 99999999;
        }
        ps[n+1] = l;
        dp[n+1] = 99999999;

        double rabbit_time = l*1.0/vr;

        dp[0] = 0;
        for (int i=1; i<=n+1; i++) {

            for (int j=0; j<i; j++) {
                int t_dis = ps[i]-ps[j];
                double t_time;
                if (c >= t_dis) {
                    t_time = t_dis*1.0/vt1;
                }
                else {
                    t_time = c*1.0/vt1 + (t_dis-c)*1.0/vt2;
                }
                if (j != 0) {
                    t_time += t;
                }
                dp[i] = min(dp[j]+t_time, dp[i]);
            }
        }
        if (dp[n+1] > rabbit_time) {
            cout<<"Good job,rabbit!"<<endl;
        }
        else {
            cout<<"What a pity rabbit!"<<endl;
        }
        
    }
    
    return 0;
}
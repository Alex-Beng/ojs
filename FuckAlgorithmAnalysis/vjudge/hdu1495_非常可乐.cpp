#include <map>
#include <queue>
#include <iostream>
using namespace std;

// a, b: cup capacity
// ta, tb: cup curr cola
// return: t_cola
int a2b(int a, int b, int& ta, int& tb) {
    if (ta>0 && tb<b) {
        int t_cola = min(ta, (b-tb));
        ta -= t_cola;
        tb += t_cola;
        return  t_cola;
    }
    return 0;
}

void status2snm(int status, int& s, int& n, int& m) {
    s = status/1000000;
    n = status/1000%1000;
    m = status%1000;
    return;
}

int bfs(int s, int n, int m) {
    // 都不超过三位数，使用int编码
    // SSS NNN MMM: cost
    std::map<int, int> cost;
    std::queue<int> qrq;
    int ts, tn, tm;

    ts = s;
    tn = 0;
    tm = 0;
    int status = ts*1000000 + tn*1000 + tm;
    qrq.push(status);
    cost[status] = 0;

    while (!qrq.empty()) {
        status = qrq.front();
        int now_cost = cost[status];
        qrq.pop();
        // cout<<status<<' '<<now_cost<<endl;
        status2snm(status, ts, tn, tm);

        if (ts<<1 == s || tn<<1 == s || tm<<1 == s) {//!
            if (ts && tn && tm) {//! 
                now_cost += 1;
            }
            return now_cost;
        }

        // 六种操作
        // S<->N  S<->M  M<->N
        int t_cola, t_status;

        // s<->n
        t_cola = a2b(s, n, ts, tn);
        t_status = ts*1000000 + tn*1000 + tm;
        if (t_cola && cost[t_status]==0) {// 倒了过去且状态从未经过
            qrq.push(t_status);
            cost[t_status] = now_cost + 1;
        }
        status2snm(status, ts, tn, tm);
        t_cola = a2b(n, s, tn, ts);//!
        t_status = ts*1000000 + tn*1000 + tm;
        if (t_cola && cost[t_status]==0) {// 倒了过去且状态从未经过
            qrq.push(t_status);
            cost[t_status] = now_cost + 1;
        }

        // s<->m
        status2snm(status, ts, tn, tm);
        t_cola = a2b(s, m, ts, tm);
        t_status = ts*1000000 + tn*1000 + tm;
        if (t_cola && cost[t_status]==0) {// 倒了过去且状态从未经过
            qrq.push(t_status);
            cost[t_status] = now_cost + 1;
        }
        status2snm(status, ts, tn, tm);
        t_cola = a2b(m, s, tm, ts);
        t_status = ts*1000000 + tn*1000 + tm;
        if (t_cola && cost[t_status]==0) {// 倒了过去且状态从未经过
            qrq.push(t_status);
            cost[t_status] = now_cost + 1;
        }

        // m<->n
        status2snm(status, ts, tn, tm);
        t_cola = a2b(n, m, tn, tm);
        t_status = ts*1000000 + tn*1000 + tm;
        if (t_cola && cost[t_status]==0) {// 倒了过去且状态从未经过
            qrq.push(t_status);
            cost[t_status] = now_cost + 1;
        }
        status2snm(status, ts, tn, tm);
        t_cola = a2b(m, n, tm, tn);
        t_status = ts*1000000 + tn*1000 + tm;
        if (t_cola && cost[t_status]==0) {// 倒了过去且状态从未经过
            qrq.push(t_status);
            cost[t_status] = now_cost + 1;
        }
    }
    
    return 0;
}

int main(int argc, char const *argv[]) {
    int s, n, m;
    int ans;
    while (1) {
        cin>>s>>n>>m;
        if ((s|n|m) == 0) {//!
            break;
        }
        ans = bfs(s, n, m);
        if (ans) {
            cout<<ans<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}
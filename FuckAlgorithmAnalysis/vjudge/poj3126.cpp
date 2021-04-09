#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
const int N = 100000;

bool is_composite[N];
int primes[N];
int prime_cnt;

void euler_filter() {
    for (int i=2; i<N; i++) {
        if (!is_composite[i]) {
            primes[prime_cnt++] = i;
        }
        for (int j=0; j<prime_cnt && i*primes[j]<N; j++) {
            is_composite[i*primes[j]] = true;
            if (i%primes[j] == 0) {
                break;
            }
        }
    }
}


int vis[N];

struct status
{
    int num;
    int c;
    status(int n) {
        num = n;
        c = 0;
    }
    status() {
        c = 0;
    }
};


int bfs(int b_num, int e_num) {
    memset(vis, 0, sizeof(vis));

    queue<status> qrq;
    status t_s(b_num), tt_s;
    qrq.push(t_s);
    vis[b_num] = 1;

    while (!qrq.empty()) {
        t_s = qrq.front();
        qrq.pop();
        // cout<<t_s.num<<' '<<t_s.c<<endl;
        if (t_s.num == e_num) {
            return t_s.c;
        }

        for (int i=0; i<=9; i++) {
            // 更换个位
            tt_s.num = t_s.num/10*10 + i;
            
            if (!is_composite[tt_s.num] && !vis[tt_s.num]) {
                // printf("ya1: %d\n", tt_s.num);
                vis[tt_s.num] = 1;
                tt_s.c = t_s.c + 1;
                qrq.push(tt_s);
            }
            // 更换十位
            tt_s.num = t_s.num/100*100 + i*10 + t_s.num%10;
            
            if (!is_composite[tt_s.num] && !vis[tt_s.num]) {
                // printf("ya2: %d\n", tt_s.num);
                vis[tt_s.num] = 1;
                tt_s.c = t_s.c + 1;
                qrq.push(tt_s);
            }
            // 更换百位
            tt_s.num = t_s.num/1000*1000 + i*100 + t_s.num%100;
            
            if (!is_composite[tt_s.num] && !vis[tt_s.num]) {
                // printf("ya3: %d\n", tt_s.num);
                vis[tt_s.num] = 1;
                tt_s.c = t_s.c + 1;
                qrq.push(tt_s);
            }
            // 更换千位
            if (i==0) {
                continue;
            }
            tt_s.num = i*1000 + t_s.num%1000;
            
            if (!is_composite[tt_s.num] && !vis[tt_s.num]) {
                // printf("ya4: %d\n", tt_s.num);
                vis[tt_s.num] = 1;
                tt_s.c = t_s.c + 1;
                qrq.push(tt_s);
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    is_composite[0] = true;
    is_composite[1] = true;
    euler_filter();

    int n, b, e;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>b>>e;
        int res = bfs(b, e);
        if (res == -1) {
            cout<<"Impossible"<<endl;
        }
        else 
            cout<<res<<endl;
    }

    return 0;
}
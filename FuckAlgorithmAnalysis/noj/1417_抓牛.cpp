#include <map>
#include <queue>
#include <iostream>
using namespace std;
int n,k;

int move_to(int t_now, int flag) {
    switch(flag) {
        case 0:
        return t_now+1;

        case 1:
        return t_now-1;

        case 2:
        return t_now*2;
        // if (t_now%2 == 0) {
        //     return t_now/2;
        // }
        // else {
        //     return -1;
        // }
    }
}

int bfs() {
    std::queue<int> qrq;
    std::map<int,int>step;
    qrq.push(n);
    while (!qrq.empty()) {
        // cout<<"here"<<endl;
        int t_now = qrq.front();
        qrq.pop();
        
        // cout<<t_now<<endl;
        for (int i=0; i<3; i++) {
            if (t_now>k && i!=1) {
                continue;
            }
            int t_next = move_to(t_now, i);
            if (t_next == -1) {
                continue;
            }
            else if (t_next == k) {
                return step[t_now]+1;
            }   
            else {
                if (step[t_next] == 0) {
                    // cout<<'h'<<t_next<<endl;
                    step[t_next] = step[t_now]+1;
                    qrq.push(t_next);
                }
                else {
                    continue;
                }
            }   
        }
    }
}

int main(int argc, char const *argv[]) {
    cin>>n>>k;
    if (n == k) {
        cout<<0<<endl;
    }
    else {
        cout<<bfs()<<endl;
    }
    
    return 0;
}

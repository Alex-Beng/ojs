#include <map>
#include <queue>
#include<iostream>
using namespace std;

int move_to(int t,int flag) {
    switch(flag) {
        case 0:
            return t+1;
        case 1:
            return t*2;
        case 2:
            return t*t;
    }
} 

int main(int argc, char const *argv[]) {
    int begin,end;
    cin>>begin>>end;
    std::queue<int> qrq;
    std::map<int,int> step;
    step[begin] = 0;
    qrq.push(begin);
    while (!qrq.empty()) {
        int t_num = qrq.front();
        int t_next;
        qrq.pop();
        for (int i=0; i<3; i++) {
            t_next = move_to(t_num,i);
            if (t_next == end) {
                cout<<step[t_num]+1<<endl;
                return 0;
            }
            if (step[t_next] == 0 && t_next < end) { //还没到且第一次到
                step[t_next] = step[t_num] + 1;
                qrq.push(t_next);
            }
        }
    }
    return 0;
}

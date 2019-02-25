#include <map>
#include <queue>
#include <iostream>
using namespace std;
std::map<int,int> to_num_step; // <num, step>
int move_to(int now_num, int flag) {
    switch(flag) {
        case 0:
            return now_num+1;
        case 1:
            return now_num*2;
        case 2:
            return now_num*now_num;
    }
}
int main(int argc, char const *argv[])
{
    int begin;
    int end;
    cin>>begin>>end;
    queue<int> qrq;
    qrq.push(begin);
    to_num_step[begin] = 0;
    while (!qrq.empty()) {
        int t = qrq.front();
        qrq.pop();
        for (int i=0;i<3;i++) {
            int t_next = move_to(t,i);
            if (t_next == end) {
                to_num_step[end] = to_num_step[t] + 1;
                cout<<to_num_step[end]<<endl;
                return 0;
            }
            if (t_next<end && to_num_step[t_next]==0) {
                to_num_step[t_next] = to_num_step[t] + 1;
                qrq.push(t_next);
            }
        }
    }
    return 0;
}

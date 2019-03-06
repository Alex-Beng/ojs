/*
sample :

1 2 3
4 0 6
7 5 8
*/
#include <map>
#include <queue>
#include <iostream>
using namespace std;
// 使用连续九位数来存当前状态
// 利用map来存step

int nine2one(int nums[9]) {
    int t = 0;
    for (int i=0; i<9; i++) {
        t = t*10 + nums[i];
    }
    return t;
}
inline void swap(int &a,int &b) {
    int t = a;
    a = b;
    b = t;
}

int slide_to(int status, int flag) { //返回-1表示滑动不合法...
    int nums[9];
    int zero_cols,zero_rows;
    for (int i=8; i>=0; i--) {
        nums[i] = status%10;
        status /= 10;

        if (nums[i] == 0) {
            // cout<<' '<<i<<endl;
            zero_rows = i/3;
            zero_cols = i%3;
        }
    }
    // for (int i=0; i<3; i++) {
    //     for (int j=0; j<3; j++) {
    //         cout<<nums[i*3+j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<zero_rows<<' '<<zero_cols<<endl;
    // cout<<nums[3*zero_rows+zero_cols]<<' '<<nums[3*(zero_rows-1)+zero_cols]<<endl;
    switch (flag) {
        case 0: //向上滑动
            if (zero_rows == 0) {
                return -1;
            }
            else { 
                swap(nums[3*zero_rows+zero_cols], nums[3*(zero_rows-1)+zero_cols]);
                // cout<<"here"<<endl;
            }
            break;
        case 1: //向左滑动
            if (zero_cols == 0) {
                return -1;
            }
            else {
                swap(nums[3*zero_rows+zero_cols], nums[3*(zero_rows)+zero_cols-1]);
            }
            break;
        case 2: //向下滑动
            if (zero_rows == 2) {
                return -1;
            }
            else {
                swap(nums[3*zero_rows+zero_cols], nums[3*(zero_rows+1)+zero_cols]);
            }
            break;
        case 3: //向右滑动
            if (zero_cols == 2) {
                return -1;
            }
            else {
                swap(nums[3*zero_rows+zero_cols], nums[3*(zero_rows)+zero_cols+1]);
            }
            break;
    }
        // for (int i=0; i<9; i++) {
        //     cout<<nums[i];
        // }
        // cout<<endl<<endl;
    return nine2one(nums);
}

int main(int argc, char const *argv[]) {
    // int t = 123456708;
    // cout<<slide_to(t,0)<<endl;

    int begin_status = 0;
    for (int i=0; i<9; i++) {
        int t;
        cin>>t;
        begin_status = 10*begin_status+t;
    }
    std::map<int ,int> step;
    std::queue<int> qrq;
    qrq.push(begin_status);
    while (!qrq.empty()) {
        int t_status = qrq.front();
        qrq.pop();
        int t_next_status;
        for (int i=0 ;i<4; i++) {
            // cout<<slide_to(t_status,i)<<endl;
            t_next_status = slide_to(t_status,i);
            // cout<<t_next_status<<endl;
            if (t_next_status == -1) {
                continue;
            }
            if (t_next_status == 123456780) {
                cout<<step[t_status] + 1<<endl;
                return 0;
            }
            if (step[t_next_status] == 0) { //第一次到这个状态
                // cout<<t_next_status<<endl;
                step[t_next_status] = step[t_status] + 1;
                qrq.push(t_next_status);
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}

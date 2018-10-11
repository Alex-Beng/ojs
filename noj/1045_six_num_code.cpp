
#include <map>
#include <queue>
#include <iostream>
using namespace std;
// 同八数码...
// 使用连续的六位数保存当前状态
// 使用map来标记是否走过

int transf_to(int status, int flag) {
    int board[2][3];
    for (int i=1; i>=0; i--) {
        for (int j=2; j>=0; j--) {
            board[i][j] = status%10;
            status /= 10;
            
        }
    }
    // for (int i=0;i<2;i++) {
    //     for (int j=0;j<3;j++) {
    //         cout<<board[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    int t;
    switch(flag) {
        case 0:
            t = board[0][0];
            board[0][0] = board[1][0];
            board[1][0] = board[1][1];
            board[1][1] = board[0][1];
            board[0][1] = t;
            break;
        case 1:
            t = board[0][1];
            board[0][1] = board[1][1];
            board[1][1] = board[1][2];
            board[1][2] = board[0][2];
            board[0][2] = t;
            break;
    }
    int ans = 0;
    for (int i=0;i<2;i++) {
        for (int j=0;j<3;j++) {
            // cout<<board[i][j]<<' ';
            ans = ans*10 + board[i][j];
        }
        // cout<<endl;
    }
    return ans;
}

int main() {
    // cout<<transf_to(123456,1);
    int t_digit[2][3];
    while (cin>>t_digit[0][0]>>t_digit[0][1]>>t_digit[0][2]
              >>t_digit[1][0]>>t_digit[1][1]>>t_digit[1][2]) {
        int begin_status = 0;
        for (int i=0;i<2;i++) {
            for (int j=0;j<3;j++) {
            begin_status = begin_status*10 + t_digit[i][j];
            }
        }

        std::queue<int> qrq;
        std::map<int, int> been;
        qrq.push(begin_status);
        while (!qrq.empty()) {
            int t_status = qrq.front();
            int t_next;
            qrq.pop();
            for (int i=0; i<2; i++) {
                t_next = transf_to(t_status,i);

                if (t_next == 123456) {
                    been[t_next] = 1;
                    while(!qrq.empty()) {
                        qrq.pop();
                    } 
                }
                if (been[t_next] == 0) {
                    been[t_next] = 1;
                    qrq.push(t_next);
                }
            }
        }
        if (been[123456] == 1) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

/**
 * abandon version
*/
// #include <map>
// #include <queue>
// #include <iostream>
// using namespace std;
// int six2one(int a[][3]) {
//     int ans = 0;
//     for (int i=0; i<2; i++) {
//         for (int j=0; j<3; j++) {
//             ans = ans*10 + a[i][j];
//         }
//     }
//     return ans;
// }

// void move_to(int num,int flag,int a[2][3]) {
//     for (int i=0; i<2; i++) {
//         for (int j=0; j<3; j++) {
//             a[i][j] = num%10;
//             num/=10;
//             // cout<<a[i][j]<<' ';
//         }
//         // cout<<endl;
//     }

//     int t;
//     switch(flag) {
//         case 0:
//             t = a[0][0];
//             a[0][0] = a[1][0];
//             a[1][0] = a[1][1];
//             a[1][1] = a[1][0];
//             a[1][0] = t;
//             break;
//         case 1:
//             t = a[0][1];
//             a[0][1] = a[1][1];
//             a[1][1] = a[1][2];
//             a[1][2] = a[0][2];
//             a[0][2] = t;
//             break;
//     }
// }

// int main(int argc, char const *argv[]) {
//     int board[2][3];
//     while (cin>>board[0][0]>>board[0][1]>>board[0][1]
//               >>board[1][0]>>board[1][1]>>board[1][2]) {
//         std::queue<int> qrq;
//         std::map<int,int> used;
        
//         qrq.push(six2one(board));
//         while (!qrq.empty()) {
//             int t_status = qrq.front();
//             qrq.pop();
//             int t_next[2][3];
//             for (int i=0; i<2; i++) {// 对应两种变换
//                 move_to(t_status,i,t_next);
//                 int t_next_digit = six2one(t_next);
//                 if (t_next_digit == 123456) {
//                     used[t_next_digit] = 1;
//                     while (!qrq.empty()) {
//                         qrq.pop();
//                     }
//                     break;
//                 }
//                 if (used[t_next_digit] == 0) { //第一次到这种状态
//                     // cout<<t_next_digit<<endl;
//                     qrq.push(t_next_digit);
//                     used[t_next_digit] = 1;
//                 }
//             }
//         } 
//         if (used[123456] == 1) {
//             cout<<"Yes"<<endl;
//         }
//         else {
//             cout<<"No"<<endl;
//         }
//     }     
//     return 0;
// }

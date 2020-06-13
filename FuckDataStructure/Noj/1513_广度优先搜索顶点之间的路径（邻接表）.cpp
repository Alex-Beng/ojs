#include <iostream>
using namespace std;
bool AJMat[101][101];

int main() {
    
    int n;
    int m;
    cin>>n>>m;
    
    int b_nd;
    int e_nd;
    for (int i=0; i<n; i++) {
        cin>>b_nd>>e_nd;
        AJMat[b_nd][e_nd] = true;
        // AJMat[e_nd][b_nd] = 1;
    }
    int qrq[101];
    int head=0;
    int tail=0;
    bool been[101];
    for (int i=0; i<m; i++) {
        cin>>b_nd>>e_nd;
        head = 0;
        tail = 0;
        qrq[tail++] = b_nd;
        for (int j=0; j<101; j++) {
            been[j] = false;
        }
        while (head != tail) {
            int t_nd = qrq[head++];
            // cout<<"t"<<t_nd<<endl;
            // if (AJMat[t_nd][3]) {
            //     cout<<"wocaonima"<<endl;
            // }
            been[t_nd] = true;
            for(int j=0; j<101; j++) {
                if (!been[j] && AJMat[t_nd][j]) {
                    // cout<<"Ya"<<j<<endl;
                    qrq[tail++] = j;
                    been[j] = true;
                } 
            }
        }

        if (been[e_nd]) {
            cout<<"Y"<<endl;
        }
        else {
            cout<<"N"<<endl;
        }
    }
    return 0;
}
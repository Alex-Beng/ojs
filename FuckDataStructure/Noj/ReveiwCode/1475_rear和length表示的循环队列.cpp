#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    int m;
    cin>>n>>m;
    int qrq[m];
    int head=0;
    int len=0;
    int t;
    for (int i=0; i<n; i++) {
        cin>>t;
        if (t==0) {
            cout<<qrq[head]<<endl;
            head = (head+1)%m;
            len--;
        }        
        else {
            if (len < m) {
                qrq[(head+len)%m] = t;
                len++;
            }
            else {
                cout<<"No"<<endl;
            }
        }
    }

}

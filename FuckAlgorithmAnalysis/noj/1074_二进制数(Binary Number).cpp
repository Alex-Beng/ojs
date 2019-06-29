#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int d;
    int t;
    cin>>d;
    for (int i=0; i<d; i++) {
        cin>>t;
        int cnt = 0;
        while (t>0) {
            if (t%2) {
                cout<<cnt;
                if (t/2 != 0)
                    cout<<' ';
            }
            t /= 2;
            cnt++;
        }
        cout<<endl;
    }
    return 0;
}
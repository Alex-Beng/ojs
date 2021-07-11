#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long n, t;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>t;
        if (t==3) {
            cout<<"1 1 1"<<endl;
            continue;
        }
        if (t%4==0 && t%2==0) {
            cout<<t/2<<' '<<t/4<<' '<<t/4<<endl;
        }
        else if (t%2==0 && t%3==0) {
            cout<<t/2<<' '<<t/3<<' '<<t/6<<endl;
        }
        else if (t%3==0) {
            cout<<t/3<<' '<<t/3<<' '<<t/3<<endl;
        }
        else {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int t;
    int max = -1;
    while (1) {
        cin>>t;
        if (t==0) {
            break;
        }
        if (t>max) {
            max = t;
        }
    }
    cout<<max<<endl;
    return 0;
}
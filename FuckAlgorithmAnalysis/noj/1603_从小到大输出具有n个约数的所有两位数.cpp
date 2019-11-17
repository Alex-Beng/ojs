#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n; 
    cin>>n;
    for (int i=10; i<100; i++) {
        int cnt=0;
        for (int j=1; j<i; j++) {
            if (i%j == 0) {
                cnt++;
            }
        }
        if (cnt == n-1) {
            cout<<i<<endl;
        }
    }
    return 0;
}
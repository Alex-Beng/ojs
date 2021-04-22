#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
    int n;
    while (cin>>n) {
        cout<<(int)(n/2.0 * (n+1) + 0.5)<<endl<<endl;
    }
    
    return 0;
}
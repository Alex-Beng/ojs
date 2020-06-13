#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, k, n, m;
    cin>>a>>k>>n>>m;
    cout<<a<<endl;
    for (int i=1; i<m; i++) {
        a = (a*a+k)%n;
        cout<<a<<endl;
    }
    return 0;
}
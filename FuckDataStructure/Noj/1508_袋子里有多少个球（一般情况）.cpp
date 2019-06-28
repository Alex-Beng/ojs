#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n,m;
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        m = (m-1)*2;
    }
    cout<<m<<endl;
    return 0;
}

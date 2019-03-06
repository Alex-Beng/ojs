#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    long int n;
    cin>>n;
    // cout<<n*2+3*n*(n-1)/2<<endl;
    if (n%2==0) {
        cout<<n*2+n/2*(n-1)*3<<endl;
    }
    else {
        cout<<n*2+(n-1)/2*n*3<<endl;
    }
    return 0;
}

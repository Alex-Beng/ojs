#include <iostream>
using namespace std;
bool IsPrime(int n) {
    if (n==1) {
        return false;
    }
    for (int i=2;i<n;i++) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    if (IsPrime(n)) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    return 0;
}

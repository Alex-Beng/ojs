#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    while (n!=1) {
        cout<<n<<endl;
        if (n%2==0) {
            n /= 2;
        }
        else {
            n = n*3+1;
        }
    }
    cout<<1<<endl;
    return 0;
}

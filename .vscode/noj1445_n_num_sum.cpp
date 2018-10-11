#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    long t;
    long sum = 0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t;
        sum+= t;
    }
    cout<<sum<<endl;
    return 0;
}

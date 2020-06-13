#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    long sum=0;
    for (int i=1; i<=n; i++) {
        sum += i*i;
    }   
    cout<<sum<<endl;
    return 0;
}
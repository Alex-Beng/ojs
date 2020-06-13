#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int sum=1;
    for (int i=2; i<n; i++) {
        if (n%i==0) {
            sum += i;
        }
    }
    if (n==sum) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    return 0;
}
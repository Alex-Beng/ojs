#include <iostream>
using namespace std;
int main() {
    int n;
    int sum = 0;
    cin>>n;
    for (int i=1;i<n;i++) {
        if (n%i==0)
            sum+=i;
    }
    if (n==sum) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}
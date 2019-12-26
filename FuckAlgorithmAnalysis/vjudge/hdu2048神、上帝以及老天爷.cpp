#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long int ans[66];
    long long int all[66];
    ans[2] = 1;
    ans[3] = 2;
    all[2] = 2;
    all[3] = 6;
    for (int i=4; i<55; i++) {
        ans[i] = (i-1)*(ans[i-1]+ans[i-2]);
        all[i] = i*all[i-1];
    }
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int t;
        cin>>t;
        cout<<fixed<<setprecision(2)
            <<1.0*ans[t]/all[t]*100<<"%"<<endl;
    }
    return 0;
}
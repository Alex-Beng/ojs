#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int t;
    int min;
    cin>>t;
    min=t;
    cin>>t;
    if (t<min)
        min=t;
    cin>>t;
    if (t<min)
        min=t;
    cout<<min<<endl;
    return 0;
}
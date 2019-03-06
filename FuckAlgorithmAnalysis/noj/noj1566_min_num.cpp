#include <algorithm>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int num[n];
    for (int i=0;i<n;i++) {
        cin>>num[i];
    }
    cout<<*std::min_element(num,num+n)<<endl;
    return 0;
}

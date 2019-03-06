#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int sum_divides;
    cin>>n;
    for (int i=2; i<=n; i++) {
        sum_divides = 0;
        for (int j=1; j<i; j++) {
            if (i%j == 0) {
                sum_divides += j;
            }
        }
        if (i==sum_divides) {
            cout<<i<<endl;
        }
    }     
    return 0;
}

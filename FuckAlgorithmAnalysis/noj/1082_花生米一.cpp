#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    while (cin>>n&&n) {
        cout<<(n%10+10-1)%10<<endl;
    }     
    return 0;
}

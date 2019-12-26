#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    while (cin>>a>>b) {
        if (!a && !b) {
            break;
        }
        int ans = a%1000;
        for (int i=0; i<b-1; i++) {
            ans *= a;
            ans %= 1000;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
#include <iostream>
using namespace std;
 
int main(int argc, char const *argv[]) {
    int n;
    int dp[2333];
    while (cin>>n && n) {
        for (int i=1; i<=n; i++) {
            if (i <= 10) {
                if (i%2 == 0) {
                    dp[i] = 1;
                }
            }
            else {
                if (dp[i-1] == 1 && dp[i-5] == 1 && dp[i-10] == 1) {
                    dp[i] = 0;
                }
                else {
                    dp[i] = 1;
                }
            }
        }
        cout<<dp[n]<<endl;
    
    }
    return 0;
}

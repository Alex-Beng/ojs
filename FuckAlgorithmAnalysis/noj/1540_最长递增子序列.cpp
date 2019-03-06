#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int num[n];
    int dp[n];
    int ans = 0;
    for (int i=0; i<n; i++) {
        cin>>num[i];
        dp[i] = 1;
        
        if (i == 0) {
            ;
        }
        else {
            for (int j=0; j<i; j++) {
                if (num[i] > num[j]) {
                    dp[i] = max(dp[i], dp[j]+1);  
                }
            }
            if (dp[i]>ans) {
                ans = dp[i];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

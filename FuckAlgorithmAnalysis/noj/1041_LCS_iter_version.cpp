#include <cstring>
#include <iostream>
using namespace std;
int dp[233][333];
int main(int argc, char const *argv[]) {
    char s1[233];
    char s2[233];
    int s1_index = 0;
    int s2_index = 0;
    cin>>s1>>s2;
    
    for (int i=1; i<=strlen(s1); i++) {
        for (int j=1; j<=strlen(s2); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[strlen(s1)][strlen(s2)]<<endl;
    return 0;
}

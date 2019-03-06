/*
sample(output 2)

programming
contest
*/
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

char s1[233];
char s2[233];
int dp[233][233];

int lcs(int L1, int L2) {

    if (L1 < 0 || L2 < 0) {
        return 0;
    }

    if (dp[L1][L2] != -1) {
        return dp[L1][L2];
    }

    if (s1[L1] == s2[L2]) {
        return dp[L1][L2] = max(lcs(L1-1,L2-1) + 1, max(lcs(L1-1, L2), lcs(L1, L2-1)));
    }
    else if (s1[L1] != s2[L2]) {
        return dp[L1][L2] = max(lcs(L1-1,L2),lcs(L1,L2-1));
    }
}

int main(int argc, char const *argv[]) {
    cin>>s1>>s2;
    memset(dp, -1, sizeof(dp));
    cout<<lcs(strlen(s1)-1,strlen(s2)-1)<<endl;
    return 0;
}

#include <iostream>
using namespace std;

long long  dp[1010];

int main(){
    dp[1] = 1;
    dp[2] = 2;
    int N;
    while( cin>>N ){
        for ( int i = 3; i <= N; i++ ){
            dp[i] = (dp[i-1] + dp[i-2])%(1000000000+7);
        }
        cout<<dp[N]<<endl;
    }
}
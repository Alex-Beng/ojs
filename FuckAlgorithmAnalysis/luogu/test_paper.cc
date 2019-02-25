#include <iostream>
using namespace std;

int main() {
	int money;	
	while (cin >> money) {
		int coin[5] = { 1,5,10,25,50 };	
		long long int dp[260] = { 0 };     
		dp[0] = 1;		
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        for (int i=0; i<5; i++) {
            for (int j=1; j<=money&&j-coin[i]>=0; j++) {
                dp[j] += dp[j-coin[i]];
            }
        }
		// for(int i = 0;i < 5;i++)	
		// {		
		// 	for(int j = coin[i];j <= money;j++)			
		// 	{			
		// 		dp[j] = dp[j] +dp[j - coin[i]];		
		// 	}	
		// }		
		cout << dp[money] << endl;
	}
	return 0;
}
// #include<bits/stdc++.h>//万能头文件
// using namespace std;
// int n;
// int f[1001];//存每一位数的种类
// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++){ //1-n的递推
//         for(int j=1;j<=i/2;j++){
//             f[i]+=f[j]; //每一位叠加，递推走起
//         }
//         f[i]++; //加上本身
//     }
//     cout<<f[n];//输出n的种类
//     return 0;
// }
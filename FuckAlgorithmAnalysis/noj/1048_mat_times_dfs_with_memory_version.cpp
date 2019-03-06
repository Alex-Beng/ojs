#include <iostream> 
using namespace std;
int n;
int for_times[23]; // 储存用于计算乘法次数的用的col&row...
int dp[23][23] = {-1};

int dfs(int begin, int end) {
    if (dp[begin][end] > 0) {
        return dp[begin][end];
    }
    if (begin == end) {
        dp[begin][end] = 0;
        return 0;
    }
    else {
        int res = 0xfffffff;
        for (int i=begin; i<end; i++) { // 等于不用了，因为跟i=begin是等效的
                                        // 而且begin == end 的情况也不用特殊考虑了，算出来是一样的
            res = min(res, dfs(begin,i)+dfs(i+1,end)+for_times[begin]*for_times[i+1]*for_times[end+1]);
        }
        dp[begin][end] = res;
        return res;
        // return min(  dfs(begin+1,end) + for_times[begin]*for_times[begin+1]*for_times[end+1],
        //              dfs(begin,end-1) + for_times[begin]*for_times[end-1+1]*for_times[end+1] );
    }
}

int main(int argc, char const *argv[]) {
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>for_times[i]>>for_times[i+1];
    }
    // cout<<endl;
    cout<<dfs(0,n-1)<<endl;
    return 0;
}

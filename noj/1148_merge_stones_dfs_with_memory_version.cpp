#include <iostream>
using namespace std;

int n;
int stones_num[233];

int get_sum(int i, int j) { // 从第i位开始的j个数之和
    int ans = 0;
    for (int t=i; t%n <= j; t++) {
        ans += stones_num[t%n];
    }
    return ans;
}

int dfs(int begin, int end) { // 从第i位开始的j个堆中合并的最小值
    if (begin == end) {
        // cout<<"here"<<endl;
        return 0;
    }
    else if (begin+1 == end) {
        return stones_num[begin] + stones_num[end];
    }
    else {
        int res = 0x7fffffff;
        for (int k=begin; k<end; k++) { 
            res = min(res, dfs(begin,k)+dfs((k+1)%n,end)+get_sum(begin,end));
        }
        return res;
    }
}

int main(int argc, char const *argv[]) {
    while (cin>>n&&n) {
        for (int i=0; i<n; i++) {
            cin>>stones_num[i];
        }
        // cout<<get_sum(3,n-1)<<endl;
        cout<<dfs(0,n-1)<<endl;
    }
    return 0;
}

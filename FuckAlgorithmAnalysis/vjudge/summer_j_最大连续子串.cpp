#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int k;
    int nums[2333];
    int begin[2333];
    int end_idx;
    int dp[2333];
    int max_sum; 
    while (1) {
        max_sum = -100000;

        cin>>k;
        if (k==0) {
            break;
        }
        else if (k==1) {
            int t;
            cin>>t;
            cout<<t<<' '<<t<<' '<<t<<endl;
            continue;
        }

        for (int i=0; i<k; i++) {
            cin>>nums[i];
            dp[i] = 0;
            begin[i] = -1;
        }
        dp[0] = nums[0];
        begin[0] = 0;
        if (nums[0] > max_sum) {
            max_sum = nums[0];
            end_idx = 0;
        }
        for (int i=1; i<k; i++) {
            if (nums[i] > nums[i]+dp[i-1]) {
                dp[i] = nums[i];
                begin[i] = i;
                if (dp[i] > max_sum) {
                    max_sum = dp[i];
                    end_idx = i;
                }
            }
            else {
                dp[i] = nums[i]+dp[i-1];
                begin[i] = begin[i-1];
                if (dp[i] > max_sum) {
                    max_sum = dp[i];
                    end_idx = i;
                }
            }
        }
        cout<<max_sum<<' '<<nums[begin[end_idx]]<<' '<<nums[end_idx]<<endl;
        
    }
    return 0;
}

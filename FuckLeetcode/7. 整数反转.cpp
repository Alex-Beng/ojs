#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        
        int ans = 0;
        // if (x<0) {ans = -1;}
        while (x!=0) {
            if (ans < INT32_MIN/10 || ans > INT32_MAX/10) {return 0;}
            int t = x%10;
            // cout<<t<<endl;
            int tt = ans*10;

            ans = (tt+t);
            // ans *= 10;
            x /= 10;
        }
        // cout<<ans<<endl;
        return ans;
        
    }
};

int main(int argc, char const *argv[]) {
    // int num = INT32_MIN;
    // num = -num;
    // cout<<num<<endl;
    Solution s;
    while (1) {
        int t;
        cin>>t;
        s.reverse(t);
    }
    
    s.reverse(120);
    return 0;
}
#include <iostream>
using namespace std;

int nums[14];
int curr_money;
int curr_nums;
int ans;

void dfs() {
    if (curr_nums > ans) {
        return ;
    }
    if (curr_money==0) {
        if (curr_nums<ans) {
            ans = curr_nums;
        }
        return ;
    }

    int t = 13;
    if (curr_money>=t && nums[t]) {
        curr_money -= t;
        curr_nums += 1;
        // cout<<curr_money<<' '<<curr_nums<<endl;
        dfs();
        curr_money -= t;
        curr_nums -= 1;
    }
    t = 11;
    if (curr_money>=t && nums[t]) {
        curr_money -= t;
        curr_nums += 1;
        // cout<<curr_money<<' '<<curr_nums<<endl;
        dfs();
        curr_money -= t;
        curr_nums -= 1;
    }
    t = 7;
    if (curr_money>=t && nums[t]) {
        curr_money -= t;
        curr_nums += 1;
        // cout<<curr_money<<' '<<curr_nums<<endl;
        dfs();
        curr_money -= t;
        curr_nums -= 1;
    }
    t = 3;
    if (curr_money>=t && nums[t]) {
        curr_money -= t;
        curr_nums += 1;
        // cout<<curr_money<<' '<<curr_nums<<endl;
        dfs();
        curr_money -= t;
        curr_nums -= 1;
    }
    t = 1;
    if (curr_money>=t && nums[t]) {
        curr_money -= t;
        curr_nums += 1;
        // cout<<curr_money<<' '<<curr_nums<<endl;
        dfs();
        curr_money -= t;
        curr_nums -= 1;
    }
}

int main(int argc, char const *argv[]) {
    
    cin>>nums[1]>>nums[3]>>nums[7]>>nums[11]>>nums[13];
    cin>>curr_money;

    ans = 10000000;
    curr_nums = 0;
    dfs();

    cout<<ans<<endl;

    return 0;
}
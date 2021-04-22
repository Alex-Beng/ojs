#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::string t_str;
    std::map<std::string, int> str2num;
    while(cin>>n) {
        if (n==0) break;

        str2num.clear();
        for (int i=0; i<n; i++) {
            cin>>t_str;
            str2num[t_str] = str2num[t_str] + 1;
        }
        int t_ans = -1;
        for (std::map<std::string, int>::iterator it = str2num.begin();
        it != str2num.end(); it++) {
            if (it->second > t_ans) {
                t_str = it->first;
                t_ans = it->second;
            }
            // cout<<it->first<<' '<<it->second<<endl;
        }
        cout<<t_str<<endl;
    }
    return 0;
}
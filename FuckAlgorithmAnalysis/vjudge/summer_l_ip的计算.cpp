#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
    char raw_str[101];

    int t_num ;
    bool correct_flag;
    while (cin>>raw_str) {
        t_num = 0;  
        correct_flag = true;
        for (int i=0; i<strlen(raw_str); i++) {
            if (raw_str[i] == ' ') {
                correct_flag = false;
                break;
            }
            if (raw_str[i] != '.') {
                t_num *= 10;
                t_num += (raw_str[i]-'0');
            }
            else {
                // cout<<"ya"<<t_num<<endl;
                if (t_num > 255) {
                    correct_flag = false;
                }
                t_num = 0;
            }
        }
        if (t_num > 255) {
            correct_flag = false;
        }
        
        if (correct_flag) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

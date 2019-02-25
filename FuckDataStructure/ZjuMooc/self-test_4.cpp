#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// bool showed[10] = {true};
std::vector<int> showed(10, -1);

int main() {
    int digits_len;
    char big_nums_str[22];
    cin>>big_nums_str;
    digits_len = strlen(big_nums_str);
    // reverse the big num
    for (int i=0; i<(digits_len)/2; i++) {
        swap(big_nums_str[i], big_nums_str[digits_len-1-i]);
    }
    // cout<<big_nums_str<<endl;

    int carry_in = 0;
    for (int i=0; i<digits_len; i++) {
        showed[big_nums_str[i]-'0'] = ~showed[big_nums_str[i]-'0'];

        big_nums_str[i] = (big_nums_str[i]-'0')*2 + '0';
        big_nums_str[i] += carry_in;
        carry_in = (big_nums_str[i]-'0')/10;
        big_nums_str[i] = (big_nums_str[i]-'0')%10 + '0';

        showed[big_nums_str[i]-'0'] = ~showed[big_nums_str[i]-'0'];
    }
    if (carry_in == 0) {
        ;
    }
    else {
        big_nums_str[digits_len] = '1';
        digits_len++;
        showed[carry_in] = ~showed[carry_in];
    }
    bool show_yes = true;
    for (int i=0; i<=9; i++) {
        if (!showed[i]) {
            show_yes = false;
        }
    }
    if (show_yes) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    for (int i=digits_len-1; i>=0; i--) {
        cout<<big_nums_str[i];
    }
    // cout<<big_nums_str<<endl;
    return 0;
}
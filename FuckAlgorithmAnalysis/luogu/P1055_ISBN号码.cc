#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    char raw_str[233];
    cin>>raw_str;

    int sum = 0;
    int for_times = 1;
    for (int i=0; i<strlen(raw_str)-1; i++) {
        if (raw_str[i] == '-') {
            continue;
        }
        else {
            sum += for_times*(raw_str[i] - '0');
            for_times++;
        }
    }

    char for_show;
    if (sum%11 == 10) {
        for_show = 'X';
    }
    else {
        for_show = '0'+sum%11;
    }

    if (for_show == raw_str[strlen(raw_str)-1]) {
        cout<<"Right"<<endl;
    }
    else {
        for (int i=0; i<strlen(raw_str)-1; i++) {
            cout<<raw_str[i];
        }
        cout<<for_show<<endl;
    }
    return 0;
}

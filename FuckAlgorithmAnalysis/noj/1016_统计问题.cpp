#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    char str[2333];
    cin.getline(str, 255);
    // cout<<str<<endl;
    int min[26];
    int max[26];
    for (int i=0; i<26; i++) {
        min[i] = 0;
        max[i] = 0;
    }

    for (int i=0; i<strlen(str); i++) {
        if ('a'<=str[i]&&str[i]<='z') {
            // cout<<"!"<<str[i]<<'!'<<endl;
            min[str[i]-'a']++;
        }
        else if ('A'<=str[i]&&str[i]<='Z'){
            // cout<<"!"<<str[i]<<'!'<<endl;
            max[str[i]-'A']++;
        }
            
    }
    int min_cnt = 0;
    int max_cnt = 0;
    for (int i=0; i<26; i++) {
        if (min[i])
            min_cnt++;
        if (max[i])
            max_cnt++;
    }
    cout<<max_cnt<<endl<<min_cnt<<endl;
    return 0;
}
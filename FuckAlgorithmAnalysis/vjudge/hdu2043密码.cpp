#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

bool pw_valid(char* str) {
    if (strlen(str)<8 || strlen(str)>16) {
        return false;
    }
    int used = 0;
    for (int i=0; i<strlen(str); i++) {
        if ('a'<=str[i] && str[i]<='z') {
            used++;
            break;
        }
    }

    for (int i=0; i<strlen(str); i++) {
        if ('A'<=str[i] && str[i]<='Z') {
            used++;
            break;
        }
    }

    for (int i=0; i<strlen(str); i++) {
        if ('0'<=str[i] && str[i]<='9') {
            used++;
            break;
        }
    }
    for (int i=0; i<strlen(str); i++) {
        if (str[i]=='~' || str[i]=='!' || str[i]=='@' || str[i]=='#' 
            || str[i]=='$' || str[i]=='%' || str[i]=='^' ) {
            used++;
            break;
        }
    }
    if (used >= 3) {
        return true;
    }
    else {
        return false;
    }
}


int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        char str[66];
        cin>>str;
        if (pw_valid(str)) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(map<char, char>& s2f_1, map<char, char>& s2f_2);

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    char info_1[n][3]; 
    char info_2[n][3]; 
    
    for (int i=0; i<n; i++) {
        cin>>info_1[i][0]
           >>info_1[i][1]
           >>info_1[i][2];
    }
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>info_2[i][0]
           >>info_2[i][1]
           >>info_2[i][2];
    }
    if (n==1) {
        if (info_1[0][0] == info_2[0][0]) {
            printf("Yes");
        }
        else {
            printf("No");
        }
        return 0;
    }
    
    char nums2char[n];
    map<char, char> son2father_1;
    map<char, char> son2father_2;
    for (int i=0; i<n; i++) {
        nums2char[i] = info_1[i][0];
    }
    for (int i=0; i<n; i++) {
        for (int j=1; j<=2; j++) {
            if (info_1[i][j] != '-') {
                char t_son = nums2char[info_1[i][j] - '0'];
                son2father_1[t_son] = info_1[i][0];
            }
        }
    }
    for (int i=0; i<n; i++) {
        nums2char[i] = info_2[i][0];
    }
    for (int i=0; i<n; i++) {
        for (int j=1; j<=2; j++) {
            if (info_2[i][j] != '-') {
                char t_son = nums2char[info_2[i][j] - '0'];
                son2father_2[t_son] = info_2[i][0];
            }
        }
    }
    if (check(son2father_1, son2father_2)) {
        printf("Yes");
    }
    else {
        printf("No");
    }
    
    return 0;
}

bool check(map<char, char>& s2f_1, map<char, char>& s2f_2) {
    for (auto i=s2f_1.begin(); i!=s2f_1.end(); i++) {
        char son = i->first;
        char father = i->second;
        auto temp = s2f_2.find(son);
        if (temp == s2f_2.end()) { // Not found this son
            return false;
        }
        else {// else check its father
            if (temp->second != father) {
                return false;
            }
        }
    }
    return true;
}
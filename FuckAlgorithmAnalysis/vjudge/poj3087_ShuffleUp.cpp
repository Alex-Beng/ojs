#include <cstdio>

#include <map>
#include <string>
#include <iostream>
using namespace std;

std::string shuffle(std::string& s1, std::string& s2) {
    int c = s1.length();
    std::string t_res = "";
    for (int i=0; i<c; i++) {
        t_res += s2[i];
        t_res += s1[i];
    }

    s1 = t_res.substr(0, c);
    s2 = t_res.substr(c, c);
    return t_res;
}

int search(std::string s1, std::string s2, std::string wanted) {
    std::string t_res = shuffle(s1, s2);
    std::map<std::string, int> been;
    int cost = 1;
    while (t_res != wanted && !been[t_res]) {
        been[t_res] = 1;
        cost++;
        t_res = shuffle(s1, s2);
    }
    if (t_res == wanted) return cost;
    else return -1;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;

    int c;
    std::string s1, s2, wanted;
    std::string t_res;
    std::map<std::string, int> been;
    int cost = 0;
    for (int i=0; i<n; i++) {
        cin>>c>>s1>>s2>>wanted;

        printf("%d %d\n", i+1, search(s1, s2, wanted));
        continue;        
    }
    return 0;
}
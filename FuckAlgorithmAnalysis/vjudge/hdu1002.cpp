#include <cstdio>
#include <cstring>

#include <string>
#include <iostream>
using namespace std;

void s2n(std::string s, int n[2333]) {
    int cnt = 0;
    for (int i=s.size()-1; i>=0; i--) {
        n[cnt++] = s[i]-'0';
    }
}

void out_num(int n[2333], int len) {
    for (int i=len-1; i>=0; i--) {
        cout<<n[i];
    }
}

int main(int argc, char const *argv[]) {
    std::string as, bs;
    int a[2333], b[2333], res[2333];

    int n;
    cin>>n;
    for (int ii=0; ii<n; ii++) {
        cin>>as>>bs;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(res, 0, sizeof(res));

        s2n(as, a);
        s2n(bs, b);

        int len = max(as.size(), bs.size());
        for (int i=0; i<len; i++) {
            res[i] += a[i]+b[i];
            if (res[i]>9) {
                res[i] = res[i]%10;
                res[i+1] += 1;
            }
        }
        if (res[len] == 1)
            len++;

        printf("Case %d:\n", ii+1);
        out_num(a, as.size());
        cout<<" + ";
        out_num(b, bs.size());
        cout<<" = ";
        out_num(res, len);
        cout<<endl;
        if (ii!=n-1) cout<<endl;
    }
    return 0;
}
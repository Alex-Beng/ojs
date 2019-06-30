#include <algorithm>
#include <iostream>
using namespace std;

struct people {
    int code;
    int chin;
    int math;
    int engl;
    int sum;
    void input(int cd) {
        code = cd;
        cin>>chin;
        cin>>math;
        cin>>engl;
        sum = chin+math+engl;
        // cout<<sum<<endl;
    }
};

bool for_sort(people &a, people &b) {
    if (a.sum != b.sum) {
        return a.sum<b.sum;
    }
    else {
        if (a.chin != b.chin) {
            return a.chin<b.chin;
        }
        else {
            return a.code>b.code;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    people pp[n];
    for (int i=0; i<n; i++) {
        pp[i].input(i+1);
    }
    sort(pp, pp+n, for_sort);
    for (int i=n-1; i>=0&&i>=n-5; i--) {
        cout<<pp[i].code<<' '<<pp[i].sum<<' '<<endl;
    }

    return 0;
}
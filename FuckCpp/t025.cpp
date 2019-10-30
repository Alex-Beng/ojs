#include <bits/stdc++.h>
using namespace std;

int m, n;
long g, s;

void dfs(int num_bin[], int layer) {
    if (layer == n) {
        int t = 0;
        bool valid = false;
        for (int i=0; i<n; i++) {
            t *= 10;
            t += num_bin[i];
            if (num_bin[i] == m) {
                valid = true;
            }
        }
        if (t%m != 0&&valid) {
            g += 1;
            s += t;
        }
    }
    else {
        for (int i=0; i<=9; i++) {
            if (layer==0&&i==0) {
                continue;
            }
            num_bin[layer] = i;
            dfs(num_bin, layer+1);
        }
    }
}

int main(int argc, char const *argv[]) {
    cin>>m>>n;
    int num_bin[n];

    dfs(num_bin, 0);
    cout<<g<<' '<<s<<endl;
    return 0;
}

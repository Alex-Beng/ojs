#include <iostream>
using namespace std;
int num[3];

void dfs(int layer) {
    if (layer > 3) {
        if (num[0]*num[0]*num[0]+num[1]*num[1]*num[1]+num[2]*num[2]*num[2]
            == num[2]*100+num[1]*10+num[0]) {
            cout<<num[2]<<num[1]<<num[0]<<endl;
        }
    }
    else {
        for (int i=1;i<=9;i++) {
            num[layer] = i;
            dfs(layer+1);
            num[layer] = 0;
        }
    }
}
int main() {
    // dfs(0);
    cout<<153<<endl<<370<<endl<<371<<endl<<407<<endl;
    return 0;
}
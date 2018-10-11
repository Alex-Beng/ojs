#include <iostream>
using namespace std;
int num_to_fill[3]={-1};
int system = 10;
int ans = 0;
void dfs(int layer) {
    if (layer == 3) {
        int t_num_1 = system*system*num_to_fill[0]+system*num_to_fill[1]+6;
        int t_num_2 = num_to_fill[2];
        if (t_num_1*t_num_2 == system*system*8+system*8+9) {
            cout<<system<<' '<<system*system*num_to_fill[0]<<' '<<system*num_to_fill[1]<<' '<<6<<'*'<<t_num_2<<'='<<889<<endl;
            ans ++;
        }
    }
    else {
        for (int i=1; i<=system-1; i++) {
            num_to_fill[layer] = i;
            dfs(layer+1);
            num_to_fill[layer] = -1;
        }
    }
}
int main(int argc, char const *argv[]) {
    for (int i=1137;i<=1290;i++) {
        if (i%2==0){
            continue;
        }
        system = i;
        // cout<<"system: "<<i<<endl;
        dfs(0);
    }
    cout<<ans<<endl;

    return 0;
}

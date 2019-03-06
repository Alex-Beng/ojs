#include <iostream>
using namespace std;

int n,c,c2;
int w[20];
int ans = 0;
bool used[20];
void check_ans() {
    int t_sum_weight = 0;
    for (int i=0;i<n;i++){
        if (used[i]){
            t_sum_weight += w[i];
        }
    }
    if (t_sum_weight<=c && t_sum_weight > ans){
        ans = t_sum_weight;
    }
}

void dfs( int layer ) {
    if (layer >= n) {
        check_ans();
    }
    else {
        used[layer] = false;
        dfs(layer+1);
        used[layer] = true;
        dfs(layer+1);
    }
}

int main() {
    int all_weight;
    while (cin>>c>>c2>>n && (n||c||c2)){
        ans = 0;
        all_weight = 0;
        for (int i= 0; i < n; i++) {
            cin>>w[i];
            all_weight += w[i];
            used[i] = false;
        }
        dfs(0);
        // cout<<ans<<endl;
        if (all_weight-ans<=c2){
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

/**
 * Abandoned Version 
*/
// #include <cstdlib>
// #include <iostream>
// using namespace std;
// __int64 ship1_capacity;
// __int64 ship2_capacity;
// __int64 things_num;
// __int64 weight[20];

// __int64 t_ship1_capacity;
// __int64 max_ship1_capacity;

// void check_max(){
//     if (t_ship1_capacity > max_ship1_capacity&& t_ship1_capacity<=ship1_capacity){
//         max_ship1_capacity = t_ship1_capacity;
//     }
// }

// void dfs( __int64 index ) {
//     if ( index >= things_num ) { //搜索到最后一层
//         check_max();
//     }
//     else {
//         dfs( index+1 ); //不装
//         t_ship1_capacity += weight[index];
//         dfs( index+1 );
//     }
// }

// int main() {
//     __int64 sum_weight;
//     while (cin>>ship1_capacity>>ship2_capacity>>things_num && (ship1_capacity || things_num || ship2_capacity)){
//         sum_weight = 0;
//         for (int i=0; i<things_num; i++) {
//             cin>>weight[i];
//             sum_weight += weight[i];
//         }
//         t_ship1_capacity = 0;
//         max_ship1_capacity = 0;
//         dfs(0);
//         // cout<<max_ship1_capacity<<endl;
//         if ( sum_weight-max_ship1_capacity <= ship2_capacity ) {
//             cout<<"Yes"<<endl;
//         }
//         else {
//             cout<<"No"<<endl;
//         }
//     }
//     return 0;
// }

/**
 * Both AC Version, choose by yourself.
*/


// #include <iostream>
// using namespace std;
// int capacity;
// int things_num;
// int weight[20];
// int value[20];
// int max_sum_value; 
// int t_sum_value;
// int t_capacity;
// void dfs( int index ) {
//     if ( index == things_num ) { //搜索到最后一层
//         if ( t_sum_value > max_sum_value ){
//             max_sum_value = t_sum_value;
//         }
//     }
//     else {
//         // 先不加
//         dfs( index+1 );
//         // 然后再尝试加进去
//         t_sum_value += value[index];
//         t_capacity -= weight[index];
//         if (t_capacity<0) {// 包炸了, 不能放, 剪枝
//             t_sum_value -= value[index];
//             t_capacity += weight[index];
//             return ;
//         }
//         else { // 如果能放
//             dfs(index+1);
//         }
//     }
// }

// int main() {
   
//     while (cin>>things_num>>capacity && (capacity || things_num)){
//         max_sum_value = -1;
//         for (int i=0; i<things_num; i++) {
//             cin>>weight[i];
//         }
//         for (int i=0; i<things_num; i++) {
//             cin>>value[i];
//         }
//         t_sum_value = 0;
//         t_capacity = capacity;
//         dfs(0);
//         cout<<max_sum_value<<endl;
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

int n,c;
int w[20], v[20];
int ans = 0;
bool used[20];
void check_ans() {
    int t_sum_weight = 0;
    int t_sum_value = 0;
    for (int i=0;i<n;i++){
        if (used[i]){
            t_sum_weight += w[i];
            t_sum_value += v[i];
        }
    }
    if (t_sum_weight<=c && t_sum_value>ans){
        ans = t_sum_value;
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
    
    while (cin>>n>>c && (n||c)){
        ans = 0;
        for (int i= 0; i < n; i++) {
            cin>>w[i];
            used[i] = false;
        }
        for (int i= 0; i < n; i++) {
            cin>>v[i];
        }
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
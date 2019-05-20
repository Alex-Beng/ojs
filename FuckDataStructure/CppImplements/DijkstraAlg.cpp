#include "AjacentMat.h"

int main(int argc, char const *argv[]) {
    AjacentMat<int> ajm;
    ajm.input();
    int n = ajm.getNodeNum();
    int begin_node;
    int end_node;
    cin>>begin_node>>end_node;


    int  distance[n];
    bool visited[n];
    int  path[n];
    int  path_pointer = 0;

    for (int i=0; i<n; i++) {
        visited[i] = false;
        distance[i] = ajm.getValue(begin_node, i);
    }
    distance[0] = 0;

    int ans_path[n];
    int ans_path_len;

    int node_cnt = begin_node;
    while (visited[node_cnt]==false){
        visited[node_cnt] = true;

        for (int i=0; i<n; i++) {
            if (ajm.getValue(node_cnt, i) < 10000) {// 如果联通 
                if (distance[node_cnt]+ajm.getValue(node_cnt, i) < distance[i]) {
                    distance[i] = distance[node_cnt]+ajm.getValue(node_cnt, i);
                    if (i == end_node) {
                        ans_path_len = path_pointer;
                        for (int j=0; j<path_pointer; j++) {
                            ans_path[j] = path[j];
                        }
                    }
                }
                else {
                    ;
                }
            }

        }

        int min_path = 99999;
        for (int i=0; i<n; i++) {
            if (ajm.getValue(node_cnt, i) < 10000) {
                if (visited[i]==false && distance[i]<min_path) {
                    min_path = distance[i];
                    node_cnt = i;
                }
            }
        }
        path[path_pointer++] = node_cnt;
    }
    // cout<<"ya"<<ans_path_len<<endl;
    cout<<begin_node<<endl;
    for (int i=0; i<ans_path_len; i++) {
        cout<<ans_path[i]<<endl;
    }
    cout<<end_node<<endl;
    // for (int i=0; i<n; i++) {
    //     cout<<distance[i]<<endl;
    // }

    return 0;
}

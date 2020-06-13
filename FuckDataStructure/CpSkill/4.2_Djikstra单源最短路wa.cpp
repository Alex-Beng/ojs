/*
6
0 1 10000 10000 10000 10000
1 0 2 10000 1 10000
10000 2 0 3 10000 10000
10000 10000 3 0 10000 10000
10000 1 10000 10000 0 1
10000 10000 10000 10000 1 0
0 3
*/

#include <iostream>
using namespace std;

template<class T>
class AjacentMat {
protected:
    T* data;
    int n;
public:
    AjacentMat(){}
    ~AjacentMat(){delete [] data;}
    void input();
    T getValue(int row, int col);
    void setValue(int row, int col, T value);
    T getNodeNum(){return n;}
};

template<class T>
void AjacentMat<T>::input() {
    cin>>n;
    if (n <= 0) {
        return;
    }
    data = new T[n*n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>data[i*n+j];
        }
    }
}

template<class T>
T AjacentMat<T>::getValue(int row, int col) {
    return data[row*n+col];
}

template<class T>
void AjacentMat<T>::setValue(int row, int col, T value) {
    data[row*n+col] = value;
}


bool AllNodeVisited(bool* arr, int n) {
    for (int i=0; i<n; i++) {
        if (arr[i] == false) {
            return false;
        }
    }
    return true;
}

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
        // cout<<distance[i]<<' '<<endl;
    }
    distance[0] = 0;

    int ans_path[n];
    int ans_path_len = 0;

    // int all_paths[n][n+2]; // from begin node to the other nodes' paths
    // for (int i=0; i<n; i++) {
    //     all_paths[i][0] = 0;
    // }

    int node_cnt = begin_node;
    while (!AllNodeVisited(visited, n)){
        // cout<<node_cnt<<" tracking"<<endl;
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

                    // update paths
                    // all_paths[i][0] = path_pointer;
                    // for (int j=0; j<path_pointer; j++) {
                    //     all_paths[i][j+1] = path[j];
                    // }
                }
                else {
                    ;
                }
            }

        }

        int min_path = 99999;
        bool no_signal = true;// 是否丢失了信号
        int new_node = node_cnt;
        for (int i=0; i<n; i++) {
            if (ajm.getValue(node_cnt, i) < 10000) {
                if (visited[i]==false && ajm.getValue(node_cnt, i)<min_path) {
                    min_path = ajm.getValue(node_cnt, i);
                    new_node = i;
                    no_signal = false;
                }
            }
        }
        if (no_signal) {
            // cout<<'y'<<node_cnt<<endl;
            // for (int i=0; i<n; i++) {
            //     cout<<distance[i]<<' ';
            // }
            // cout<<endl;
            // cout<<"yayaya"<<node_cnt<<endl;
            node_cnt = path[path_pointer-2];
            path_pointer--;
            for (int i=0; i<path_pointer; i++) {
                // cout<<"v"<<path[i];
            }
            // cout<<endl;
            continue;
            // for (int i=0; i<n; i++) {
            //     if(distance[i]>=10000) {
            //         cout<<"hahaha"<<i<<endl;
            //         node_cnt = i;

            //         path_pointer = all_paths[node_cnt][0];
            //         for (int j=0; j<all_paths[node_cnt][0]; j++) {
            //             path[j] = all_paths[node_cnt][j+1];
            //         }

            //         break;
            //     }
            // }
        }
        else {
            node_cnt = new_node;
        }
        path[path_pointer++] = node_cnt;
        for (int i=0; i<path_pointer; i++) {
            // cout<<"v"<<path[i];
        }
        // cout<<endl;
    }
    // cout<<"ya"<<ans_path_len<<endl;
    // cout<<'y'<<endl;
    // for (int i=0; i<path_pointer; i++) {
    //     cout<<path[i]<<' ';
    // }
    // cout<<endl;
    cout<<begin_node<<endl;
    // for (int i=0; i<all_paths[end_node][0]; i++) {
    //     cout<<all_paths[end_node][i]<<endl;
    // }
    for (int i=0; i<ans_path_len; i++) {
        cout<<ans_path[i]<<endl;
    }

    cout<<end_node<<endl;
    // for (int i=0; i<n; i++) {
    //     cout<<distance[i]<<endl;
    // }
    // cout<<ajm.getValue(1, 2)<<ajm.getValue(1, 4)<<endl;

    return 0;
}

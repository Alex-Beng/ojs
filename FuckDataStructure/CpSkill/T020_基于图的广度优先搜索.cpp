/*
4 4
1 2 3 4
1 2
1 3
1 4
2 3
2 3
*/
#include <iostream>
using namespace std;

struct node {
    string name;
    int idx;
};


bool aj_mat[233][333];
int n;
int m;
node nodes[101];

bool been[101];
bool ans;


int name2idx(string name) {
    for (int j=0; j<n; j++) {
        if (nodes[j].name == name) {
            return j;
        }
    }
}

void bfs(int idx_1, int idx_2) {
    int queue[n];
    int queue_head = -1;
    int queue_tail = 0;
    
    queue[queue_head+1] = idx_1;
    been[idx_1] = true;

    while (queue_head <= queue_tail) {
        int ttt = queue_tail;
        for (int i=queue_head+1; i<=ttt; i++) {
            for (int j=0; j<n; j++) {
                if (aj_mat[i][j] && !been[j]) {
                    queue[++queue_tail] = j;
                    been[j] = true;
                    if (j == idx_2) {
                        ans = true;
                        return ;
                    }
                }
            }
        }
        queue_head = ttt-1;
    }
}

int main(int argc, char const *argv[]) {
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>nodes[i].name;
        // cout<<nodes[i].name<<endl;
        nodes[i].idx = i;
    }
    string name_1;
    string name_2;
    int idx_1;
    int idx_2;
    for (int i=0; i<m; i++) {
        cin>>name_1>>name_2;

        idx_1 = name2idx(name_1);
        idx_2 = name2idx(name_2);
        // cout<<"a"<<idx_1<<' '<<idx_2<<endl;

        aj_mat[idx_1][idx_2] = true;
        aj_mat[idx_2][idx_1] = true;
    }

    cin>>name_1>>name_2;
    // cout<<name_1<<'a'<<name_2<<endl;
    idx_1 = name2idx(name_1);
    idx_2 = name2idx(name_2);
    // cout<<idx_1<<' '<<idx_2<<endl;
    bfs(idx_1, idx_2);
    // cout<<123<<endl;
    if (ans) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }

    return 0;
}

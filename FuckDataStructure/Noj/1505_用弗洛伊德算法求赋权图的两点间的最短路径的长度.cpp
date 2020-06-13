#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int AJMat[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>AJMat[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (AJMat[j][i]+AJMat[i][k] < AJMat[j][k]) {
                    AJMat[j][k] = AJMat[j][i]+AJMat[i][k];
                }
            }
        }
    }

    int m;
    int begin_node;
    int end_node;
    cin>>m;
    for (int i=0; i<m; i++) {
        cin>>begin_node>>end_node;
        cout<<AJMat[begin_node][end_node]<<endl;
    }
    return 0;
}
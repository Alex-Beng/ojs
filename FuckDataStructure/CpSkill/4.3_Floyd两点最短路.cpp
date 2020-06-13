/**
6
0       1       4       10000   10000   10000
1       0       2       7       5       10000
4       2       0       10000   1       10000
10000   7       10000   0       3       2
10000   5       1       3       0       6
10000   10000   10000   2       6       0
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

int main(int argc, char const *argv[]) {
    AjacentMat<int> ajm;
    ajm.input();
    int n = ajm.getNodeNum();

    for (int k=0; k<n; k++) {
        for (int j=0; j<n; j++) {
            for (int i=0; i<n; i++) {
                // if (i==0 && j==n-1)
                //     cout<<ajm.getValue(i, k)+ajm.getValue(k, j)<<' '<<ajm.getValue(i, j)<<endl;
                if (ajm.getValue(i, k)+ajm.getValue(k, j) < ajm.getValue(i, j)) {
                    ajm.setValue(i, j, ajm.getValue(i, k)+ajm.getValue(k, j));
                }
            }
        }
    }
    int m;
    int node1, node2;
    cin>>m;
    for (int i=0; i<m; i++) {
        cin>>node1>>node2;
        cout<<ajm.getValue(node1, node2)<<endl;
    }
    return 0;
}
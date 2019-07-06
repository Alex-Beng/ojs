#include <iostream>
using namespace std;

void GenNext(int* array, int cnt) {
    array[0] = 1;
    int t_pre = 1;
    int t;
    for (int i=1; i<cnt-1; i++) {
        t = array[i];
        array[i] = t_pre + array[i];
        t_pre = t;
    }
    array[cnt-1] = 1;
}

int main(int argc, char const *argv[]) {
    int tri[23];
    tri[0] = 1;
    tri[1] = 1;
    GenNext(tri, 3);
    int n; 
    cin>>n;
    for (int i=1; i<n+1; i++) {
        GenNext(tri, i);
        for (int j=0; j<i; j++) {
            cout<<tri[j];
            if (j!=i-1) {
                cout<<' ';
            }
        }
        cout<<endl;
    }

    return 0;
}
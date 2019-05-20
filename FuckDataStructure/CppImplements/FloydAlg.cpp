#include "AjacentMat.h"

int main(int argc, char const *argv[]) {
    AjacentMat<int> ajm;
    ajm.input();
    int n = ajm.getNodeNum();

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (ajm.getValue(i, k)+ajm.getValue(k, j) < ajm.getValue(i, j)) {
                    ajm.setValue(i, j, ajm.getValue(i, k)+ajm.getValue(k, j));
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        cout<<ajm.getValue(0, i)<<endl;
    }   
    return 0;
}

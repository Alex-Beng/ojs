#include <iostream>
using namespace std;

int n;
int bits[23];

void show(int layer) {
    if (layer == n) {
        for (int i=0; i<n; i++) {
            cout<<bits[i];
        }
        cout<<endl;
    }
    else {
        for (int i=0; i<2; i++) {
            bits[layer] = i;
            show(layer+1);
        }
    }
}

int main(int argc, char const *argv[]) {
    cin>>n;
    show(0);
    return 0;
}

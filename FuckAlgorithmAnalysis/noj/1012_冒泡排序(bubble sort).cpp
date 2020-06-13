#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin>>array[i];
    }

    int t;
    for (int i=n-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (array[j]>array[j+1]) {
                t = array[j+1];
                array[j+1] = array[j];
                array[j] = t;
            }
        }
    }
    for (int i=0; i<n; i++) {
        cout<<array[i]<<endl;
    }
    return 0;
}
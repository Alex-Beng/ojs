#include <iostream>
using namespace std;

bool binary_search(int* array, int left, int right, int num) {
    if (left+1 != right) {
        int middle = (left+right) / 2;
        if (array[middle] > num) {
            return binary_search(array, left, middle, num);
        }
        else if (array[middle] < num) {
            return binary_search(array, middle, right, num);
        }
        else {
            return true;
        }
    }
    else {
        if (array[left] != num && array[right] != num) {
            return false;
        }
        else {
            return true;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int array[n];
    for (int i=0; i<n ;i++) {
        cin>>array[i];
    }
    int m;
    int num;
    cin>>m;
    for (int i=0; i<m; i++) {
        // cout<<"ya"<<endl;
        cin>>num;
        if (binary_search(array, 0, n-1, num)) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

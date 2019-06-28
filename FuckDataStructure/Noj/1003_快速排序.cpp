#include <iostream>
using namespace std;

// 返回分割点
int partition(int* array, int left, int right) {
    int sign_num = array[left];

    while (left < right) {
        while (left < right && array[right]>=sign_num) {
            right--;
        }
        array[left] = array[right];
        while (left < right && array[left]<=sign_num) {
            left++;
        }
        array[right] = array[left];
    }
    array[left] = sign_num;
    return left;
}


void sort(int* array, int left, int right) {
    if (left < right) {
        int middle_point = partition(array, left, right);
        sort(array, left, middle_point-1);
        sort(array, middle_point+1, right);
    }
}



int main(int argc, char const *argv[]) {
    int n; 
    cin>>n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin>>array[i];
    }
    sort(array, 0, n-1);
    for (int i=0; i<n; i++) {
        cout<<array[i]<<endl;
    }
    return 0;
}

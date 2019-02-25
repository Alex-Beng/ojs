#include <iostream>
using namespace std;


int partition(int *num, int left, int right) {
    int pivot_num = num[left];
    while (left < right) {
        while (left < right && num[right] >= pivot_num) {
            right--;
        }
        num[left] = num[right];
        while (left < right && num[left] <= pivot_num) {
            left++;
        }
        num[right] = num[left];
    }
    num[left] = pivot_num;
    return left;
}

int linear_select(int *num, int left, int right, int target) {
    if (left < right) {
        int pivot_pointer = partition(num, left, right);
        if (pivot_pointer > target) { // 去小的那一半找
            return linear_select(num, left, pivot_pointer-1, target);
        }
        else if (pivot_pointer < target){ // 去大的那一半找
            return linear_select(num, pivot_pointer+1, right, target);
        }
        else { // 就是
            return num[pivot_pointer];
        }
    }
    else {
        return num[left];
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n; 
    int num[n];
    for (int i=0; i<n; i++) {
        cin>>num[i];
    }
    int t;
    cin>>t;
    cout<<linear_select(num, 0, n-1, t-1)<<endl;
    return 0;
}

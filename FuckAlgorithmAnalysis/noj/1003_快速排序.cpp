#include <iostream>
using namespace std;

void quick_sort(int, int, int*);
int partition(int, int, int, int*);

void quick_sort(int head, int tail, int *num) {
    if (head < tail) {
        int pivot_point = head;
        int next_pivot_point = partition(head, tail, pivot_point, num);
        quick_sort(head, next_pivot_point-1, num);
        quick_sort(next_pivot_point+1, tail, num);
    } 
}

int partition(int head, int tail, int pivot_point, int *num) {
    int t = tail;
    int pivot_num = num[pivot_point];
    while (head < tail) {
        while (head < tail && num[tail] >= pivot_num) tail--;
        num[head] = num[tail];
        while (head < tail && num[head] <= pivot_num) head++;
        num[tail] = num[head];
    }
    num[head] = pivot_num;
    // cout<<"pivot_point"<<head<<endl;
    return head;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int num[n];
    for (int i=0; i<n; i++) {
        cin>>num[i];
    }
    // quick_sort(0, n-1, num);
    partition(0, n-1, 0, num);
    for (int i=0; i<n; i++) {
        cout<<num[i]<<endl;
    }
    return 0;
}

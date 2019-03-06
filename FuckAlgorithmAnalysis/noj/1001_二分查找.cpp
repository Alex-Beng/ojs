#include <iostream>
using namespace std;

bool binary_search(int head, int end, int target, int *num) {
    if (head + 1 == end) {
        if (num[head] == target || num[end] == target) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        int middle = (head + end)/2;
        if (num[middle] < target) {
            return binary_search(middle, end, target, num);
        }
        else if (num[middle] > target) {
            return binary_search(head, middle, target, num);
        }
        else {
            return true;
        }
    }
} 

int main(int argc, char const *argv[]) {
    int n;
    int ask_times;
    cin>>n;
    int num[n];
    for (int i=0; i<n; i++) {
        cin>>num[i];
    }
    cin>>ask_times;

    int t;
    for (int i=0; i<ask_times; i++) {
        cin>>t;
        if (binary_search(0,n-1,t,num)) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

#include <iostream>
using namespace std;

class Stack {
private:
    int* sk;
    int len;
public:
    Stack() {
        sk = new int[333];
        len = 0;
    }
    void Push(int t) {
        sk[len++] = t;
    }
    void Pop() {
        cout<<sk[--len]<<endl;
    }
};


int main(int argc, char const *argv[]) {
    Stack sk;
    int n; 
    cin>>n;
    int raw_nums[n];
    int ptr = 0;
    for (int i=0; i<n; i++) {
        cin>>raw_nums[i];
    }
    int m;
    int t;
    cin>>m;
    for (int i=0; i<m; i++) {
        cin>>t;
        if (t) {
            sk.Push(raw_nums[ptr++]);
        }
        else {
            sk.Pop();
        }
    }
    return 0;
}

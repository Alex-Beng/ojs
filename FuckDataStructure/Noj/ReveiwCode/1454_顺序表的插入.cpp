#include <iostream>
using namespace std;

class LinearList {
private:
    int* array;
    int len;
public:
    LinearList() {
        array = NULL;
        len = 0;
    }
    void input() {
        cin>>len;
        array = new int[len+1];
        for (int i=0; i<len; i++) {
            cin>>array[i];
        }
    }
    void output() {
        for (int i=0; i<len; i++) {
            cout<<array[i]<<endl;
        }
    }
    void Insert(int t) {
        int pos_in;
        for (int i=1; i<len; i++) {
            if (array[i-1]<=t && t<=array[i]) {
                pos_in = i;
            }
            else if (i==len-1 && t>array[i]) {
                array[len++] = t;
                return ;
            }
        }
        for (int i=len-1; i>=pos_in; i--) {
            array[i+1] = array[i];
        }
        len++;
        array[pos_in] = t;
    }
};

int main(int argc, char const *argv[]) {
    LinearList ll;
    ll.input();
    int t;
    cin>>t;
    ll.Insert(t);
    ll.output();
    return 0;
}

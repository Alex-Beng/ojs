#include <map>
#include <iostream>
#include <functional>

using namespace std;

int main(int argc, char const *argv[]) {
    int coef, idx;
    int status = 0;
    while (cin>>coef>>idx) {
        if (idx == 0) {
            continue;
        }
        if (coef*idx != 0) {
            if (status) {
                cout<<' ';
            }
            cout<<coef*idx<<' '<<idx-1;
            status = 1;
        }
    }
    if (!status) {
        cout<<"0 0"<<endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int seq_list[100];
    int last = -1;
    cin>>last;
    last--;

    for (int i=0; i<=last; i++) {
        cin>>seq_list[i];
    }
    for (int i=last; i>=0; i--) {
        cout<<seq_list[i]<<endl;
    }
    return 0;
}

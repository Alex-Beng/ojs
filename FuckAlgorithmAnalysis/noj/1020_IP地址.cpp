#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    char binary_code[233];
    char t_c;
    for (int i=0; i<n; i++) {
        cin>>binary_code;
        // cout<<binary_code<<endl;
        int t_sum = 0;
        for (int j=0; j<strlen(binary_code); j++) {
            t_c = binary_code[j];
            t_sum *= 2;
            t_sum += (t_c-'0');
            // cout<<"a"<<t_sum<<' '<<t_c<<endl;
            if ((j+1)%8 == 0 && j != strlen(binary_code)-1) {
                // cout<<"ya"<<j<<endl;
                cout<<t_sum<<'.';
                t_sum = 0;
            }
        }
        cout<<t_sum<<endl;
    }
    return 0;
}
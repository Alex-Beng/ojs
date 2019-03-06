#include <iostream>
using namespace std;
void print_num(int n) {
    if (n<10) {
        cout<<n<<endl;
    }
    else {
        int t = n%10;
        cout<<t<<endl;
        print_num(n/10);
    }
}
int main() {
    int n;
    cin>>n;
    print_num(n);
    return 0;
}
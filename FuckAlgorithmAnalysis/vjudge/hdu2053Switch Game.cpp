#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    while (cin>>n) {
        double root = sqrt(n);
        cout<<(root == int(root))<<endl;
    }
    
    return 0;
}
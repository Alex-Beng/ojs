#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::string istr;
    cin>>istr;
    n = istr.length();
    for (int i=0; i<n; i++) {
        if (istr[i]=='A' && n-i>=3 && istr[i+1]=='C' && istr[i+2]=='M') {
            cout<<"Fun!"<<endl;
            return 0;
        }
    }
    cout<<"boring..."<<endl;

    return 0;
}
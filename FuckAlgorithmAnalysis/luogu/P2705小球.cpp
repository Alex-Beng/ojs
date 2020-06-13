#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int nr, nb;
    int c, d, e;
    cin>>nr>>nb>>c>>d>>e;
    int com = min(nr, nb);
    if (e+e > c+d) {
        cout<<c*(nr-com)+d*(nb-com)+2*e*com<<endl;
    }
    else {
        cout<<c*nr+d*nb<<endl;
    }
    return 0;
}
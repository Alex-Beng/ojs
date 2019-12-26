#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        double a, b, c;// 注意题面的正数
        cin>>a>>b>>c;
        if (
            ((a+b)>c) &&
            ((a+c)>b) &&
            ((b+c)>a) &&
            ((a-b)<c) &&
            ((b-a)<c) &&
            ((a-c)<b) &&
            ((c-a)<b) &&
            ((b-c)<a) &&
            ((c-b)<a)
        ) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
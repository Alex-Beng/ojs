#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int h1, h2;
        int m1, m2;
        int s1, s2;
        cin>>h1>>m1>>s1
           >>h2>>m2>>s2;
        
        s1 += s2;
        m1 += m2;
        h1 += h2;

        m1 += (s1/60);
        s1 %= 60;

        h1 += (m1/60);
        m1 %= 60;

        cout<<h1<<' '<<m1<<' '<<s1<<endl;
    }

    return 0;
}
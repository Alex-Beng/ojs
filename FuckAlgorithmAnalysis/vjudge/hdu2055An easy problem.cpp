#include <iostream>
using namespace std;

inline int f(char a) {
    if ('a'<=a && a<='z')
    {
        return -(a-'a'+1);
    }
    if ('A'<=a && a<='Z')
    {
        return (a-'A'+1);
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        char a;
        int b;
        cin>>a>>b;
        cout<<b+f(a)<<endl;
    }
    return 0;
}
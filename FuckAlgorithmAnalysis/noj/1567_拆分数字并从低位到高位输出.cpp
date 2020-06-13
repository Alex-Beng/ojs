#include <iostream>
using namespace std;

void dfs(int t) {
    if (t<10) {
        cout<<t<<endl;
    }
    else {
        cout<<t%10<<endl;
        dfs(t/10);   
    }
    
}

int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    dfs(t);
    return 0;
}

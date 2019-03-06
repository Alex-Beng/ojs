#include <iostream>
#include <algorithm>
using namespace std;
int n;
char list[]= {'a','a','b','c','d','e'};
void dfs(int m){
    if (m == n){
        for (int i = 1; i <= n; i++){
            cout<<list[i];
        }
        cout<<endl;
    }
    else {
        for (int i=m;i<=n;i++){
            swap(list[m],list[i]);
            dfs(m+1);
            swap(list[m],list[i]);
        }
    }
}
void D2B(int N){
    if (N==0||N==1){
        cout<<N;
    }
    else{
        int t = N%2;
        D2B(N/2);
        cout<<t;
    }
}
int main(){
    cin>>n;
    // dfs(1);
    D2B(n);
    return 0;
}



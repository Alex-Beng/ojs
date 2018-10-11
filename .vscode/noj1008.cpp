#include <iostream>
using namespace std;

int num[23];
bool used[23];
bool IsPrime(int n){
    for (int i=2; i*i<=n;i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}


void dfs( int index ) {
    if (index > 20) {
        if ( IsPrime(num[1]+num[20]) ) {
            for (int i=1;i<=20;i++) {
                if (i!=20)
                    cout<<num[i]<<' ';
                else 
                    cout<<num[i];
            }
            cout<<endl;  
            exit(0);
        }
        // exit(0);
        return ;
    }
    else {
        for (int i=1;i<=20;i++) {
            if (!used[i]) {
                used[i] = true;
                num[index] = i;
                if (index == 1){
                    dfs(index+1);
                }
                if (IsPrime(num[index-1]+num[index])){
                    dfs(index+1);
                } 
                used[i] = false;
            }
        }
        // for (int i=index;i<=20;i++) {
        //     swap(num[i],num[index]);
        //     if (IsPrime(num[index]+num[index-1])){
        //         dfs(index+1);   
        //     }
        //     swap(num[i],num[index]);
        // }
    }
}

int main(){
    for (int i=1;i<=20;i++) {
        num[i] = i;
        used[i] = false;
    }
    dfs(1);
    return 0;
}
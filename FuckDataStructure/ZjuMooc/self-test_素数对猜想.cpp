/*
好家伙，老英文文盲了
prime是素数，nmd这样搞is_prime数组里值为0的是素数，1是合数
妈的，绝了.jpg
*/
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
bool is_prime[100100]; 

bool Is_Prime(int num, int flag) {
    if (num==0 || num==1) {
        return false;
    }
    if (flag == 0) { // 普通弱智判素数
        for (int i=2; i*i<num; i++) {
            if (num%i == 0) {
                return false;
            }
        }
        return true;
    }
    else if (flag == 1) { // 埃式筛
        // bool is_prime[num+1] = {true};
        for (int i=2; i<=num ; i++) {
            if (!is_prime[i]) {
                for (int j=i*2; j<=num; j+=i) {
                    is_prime[j] = true;
                }
            }
        }
        return is_prime[num];
    }
    
}


int main() {
    is_prime[0] = true;
    is_prime[1] = true;

    int n;
    cin>>n;
    int counter = 0;
    Is_Prime(n+10, 1);
    // cout<<"here"<<endl;
    
    for (int i=2; i<=n; i++) {
        if (!is_prime[i] && !is_prime[i-2]) {
            // cout<<i<<' '<<i-2<<endl;
            counter++;
        } 
    }
    cout<<counter<<endl;
    return 0;
}
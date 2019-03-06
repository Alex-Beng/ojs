#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    while(cin>>n>>m && !(n==0 && m==0)) {
        set<int> A;
        set<int> B;
        set<int> result;
        int t;
        for (int i=0; i<n; i++) {
            cin>>t;
            A.insert(t);
        }
        for (int i=0; i<m; i++) {
            cin>>t;
            B.insert(t);
        }

        set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(result, result.begin()));
        if (result.empty()) {
            cout<<"NULL"<<endl;
        }
        else {
            set<int>::iterator it = result.begin();
            while (it != result.end()) {
                cout<<*it<<' ';
                it++;
            }
            cout<<endl;
        }
    }    
    return 0;
}

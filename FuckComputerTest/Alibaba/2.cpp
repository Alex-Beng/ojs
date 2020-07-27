#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;
int n, m;
std::vector<long long> collections;

int main(int argc, char const *argv[]) {
    
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        long long t;
        for (int j=0; j<x; j++) {
            cin>>t;
            if (j==0 || j==x-1) {
                collections.push_back(t);
            }
        }
    }
    
    std::sort(collections.begin(), collections.end());

    // for (auto& value : collections) {
    //     cout<<value<<" ";
    // }

    long long  sum = 0;
    for (int i=collections.size()-m; i<collections.size(); i++) {
        cout<<collections[i]<<' ';
        sum += collections[i];
    }
    cout<<sum<<endl;
    
    return 0;
}
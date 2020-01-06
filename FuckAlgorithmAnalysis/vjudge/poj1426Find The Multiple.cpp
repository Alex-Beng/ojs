#include <iostream>
using namespace std;

int n;
bool found;
void dfs(int layer, long long int t) {
    if (layer >= 19 || found) {
        return;
    }
    if (t%n == 0) {
        found = true;
        cout<<t<<endl;
        return;
    }
    if (!found) {
        dfs(layer+1, t*10);
        dfs(layer+1, t*10+1);
    }
}

int main(int argc, char const *argv[]) {
    while (cin>>n) {
        if (!n) {
            break;
        }
        found = false;
        dfs(0, 1);
    }
    
    return 0;
}
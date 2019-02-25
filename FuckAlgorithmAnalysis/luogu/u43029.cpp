#include <iostream>
using namespace std;

inline long times_mod_k(long a, long b, int k) {
    return ((a%k)*(b%k))%k;
}

int main(int argc, char const *argv[])
{
    long b,p;
    long ans;
    int k;
    cin>>b>>p>>k;
    ans = b;
    for (int i=1; i<p; i++) {
        ans = times_mod_k(ans,b,k);
    }
    cout<<ans<<endl;
    return 0;
}

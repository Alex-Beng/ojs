#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    while (1) {
        int n;
        cin>>n;
        if (!n) {
            break;
        }

        int xs[n], ys[n];
        for (int i=0; i<n; i++) {
            cin>>xs[i]>>ys[i];
        }
        
        int ans = 0;
        for (int i=1; i<n-1; i++) {
            int v1_x = xs[i]-xs[0];
            int v1_y = ys[i]-ys[0];

            int v2_x = xs[i+1]-xs[0];
            int v2_y = ys[i+1]-ys[0];

            ans += v1_x*v2_y - v2_x*v1_y;
        }
        cout<<fixed<<setprecision(1)<<ans*0.5<<endl;
    }
    
    return 0;
}
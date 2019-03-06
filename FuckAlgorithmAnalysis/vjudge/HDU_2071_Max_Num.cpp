#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]) {
    int t;

    while (cin>>t) {
        for (int i=0; i<t; i++) {
            int n;
            cin>>n;
            double max_num = -1.0;
            for (int j=0; j<n; j++) {
                double t_height;
                cin>>t_height;
                if (t_height > max_num) {
                    max_num = t_height;
                }
            }
            cout<<fixed<<setprecision(2)<<max_num<<endl;
        }
    }
    return 0;
}

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n,m;
	double ans = 0;
	while (cin>>n>>m) {
		ans = 0;
		for (int i=1; i<n; i++) {
			double t_pos = 1.0*i / n*(m+n);
			ans += fabs(t_pos - floor(t_pos+0.5))/(n+m);
		}
		cout<<fixed<<setprecision(4)<<ans*10000<<endl;
	} 
	return 0;
}

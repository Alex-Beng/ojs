#include <iostream>
#include <string>
#include <set>
using namespace std;
 
inline void status2int(int st[3][3], long long& t) {
    t = 0;
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            t += st[r][c];
            t *= 10;
			cout<<t<<endl;
        }
    }
    t /= 10;
}

int main() {
	int st[3][3] = {
		{4, 1, 2},
		{0, 5, 3},
		{7, 8, 6}
	};

	long long t;
	status2int(st, t);
	cout<<t<<endl;

	return 0;
}

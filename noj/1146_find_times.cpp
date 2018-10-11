#include <queue>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long n;
    while (cin>>n && n) {
        std::queue<long long> qrq;
        long long ans;
        qrq.push(1);
        while (!qrq.empty()) {
            long long t = qrq.front();
            qrq.pop();
            if (t%n == 0) {
                ans = t;
                while (!qrq.empty()) {
                    qrq.pop();
                }
                break ;
            }
            else {
                qrq.push(t*10);
                qrq.push(t*10+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

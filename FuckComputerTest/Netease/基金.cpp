#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int T;
    int M, X;
    int N, Y;
    int P;
    int Q = -1;
    int curr;
    cin>>T;

    for (int i=0; i<T; i++) {
        curr=100000;
        cin>>M>>N>>X>>Y>>P;
        if (M*X-N*Y <= 0) {
            if (curr + M*X < P) {
                cout<<-1<<endl;
            }
            else {
                cout<<(int)((P-curr)*1.0/X+0.5)<<endl;
            }
        }
        else {
            if (curr + M*X >= P) {
                cout<<(int)((P-curr)*1.0/X+0.5)<<endl;
            }
            else {
                int result_days = M;
                curr += M*X;

                int period = (int)((P-curr)*1.0/(M*X-N*Y));
                result_days += period*(M+N);
                curr += period*(M*X-N*Y);

                result_days += N;
                curr -= N*Y;

                int left_days = (int)((P-curr)*1.0/X+0.5);
                result_days += left_days;
                cout<<result_days<<endl;
            }
        }
    }
    return 0;
}

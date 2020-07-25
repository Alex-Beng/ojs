#include <iostream>
#include <unordered_map>
using namespace std;

#define LOGIN (t_op=='L')
#define NEW (t_op=='N')

int main(int argc, char const *argv[]) {
    int n;
    std::unordered_map<long long, std::string> acc2pw;
    cin>>n;

    long long t_acc;
    std::string t_pw;
    char t_op;
    for (int i=0; i<n; i++) {
        cin>>t_op>>t_acc>>t_pw;
        if (LOGIN) {
            if (acc2pw.count(t_acc)) {
                if (acc2pw[t_acc] == t_pw) {
                    cout<<"Login: OK"<<endl;
                }
                else {
                    cout<<"ERROR: Wrong PW"<<endl;
                }
            }
            else {
                cout<<"ERROR: Not Exist"<<endl;
            }
        }
        else if (NEW) {
            if (acc2pw.count(t_acc)) {
                cout<<"ERROR: Exist"<<endl;
            }
            else {
                cout<<"New: OK"<<endl;
                acc2pw[t_acc] = t_pw;
            }
        }
    }
    return 0;
}
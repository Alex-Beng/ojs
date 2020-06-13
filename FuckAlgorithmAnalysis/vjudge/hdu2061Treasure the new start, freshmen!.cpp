#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int c_n;
        string t_name;
        double t_credit;
        double t_grade;
        double gpa = 0.;
        double credits = 0;
        bool flag = false;
        cin>>c_n;
        if (c_n == 0) {
            flag = true;
            // cout<<"Sorry!"<<endl;
        }
        for (int j=0; j<c_n; j++) {
            cin>>t_name>>t_credit>>t_grade;

            if (t_grade < 60) {
                flag = true;
            }

            credits += t_credit;
            gpa += t_grade*t_credit;
        }
        if (flag) {
            cout<<"Sorry!"<<endl;
        }
        else {
            gpa /= credits;
            cout<<fixed<<setprecision(2)<<gpa<<endl;
        }
        
        if (i != n-1) {
            cout<<endl;
        }
    }
    return 0;
}
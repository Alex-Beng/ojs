#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    string num2week[8] = {"233"
                        ,"monday"
                        ,"tuesday"
                        ,"wednesday"
                        ,"thursday"
                        ,"friday"
                        ,"saturday"
                        ,"sunday"};
    int n;
    cin>>n;
    cout<<num2week[n]<<endl;
    return 0;
}
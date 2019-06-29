#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    char grade2char[233];
    for (int i=0; i<60; i++)
        grade2char[i] = 'D';
    for (int i=60; i<80; i++)
        grade2char[i] = 'C';
    for (int i=80; i<90; i++)
        grade2char[i] = 'B';
    for (int i=90; i<101; i++)
        grade2char[i] = 'A';
    int t;
    cin>>t;
    cout<<grade2char[t]<<endl;
    return 0;
}
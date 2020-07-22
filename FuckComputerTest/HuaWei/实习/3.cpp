#include <stdio.h>

#include <iostream>
using namespace std;

long long allcondition [40000];
long long wincondition [40000];
long long losecondition[40000];



int main(int argc, char const *argv[]) {
    allcondition[0] = 1;
    allcondition[1] = 1;
    allcondition[2] = 2;
    for (int i=3; i<40000; i++) {
        allcondition[i] = allcondition[i-1]+allcondition[i-2];
    }

    wincondition[1] = 1;
    wincondition[2] = 1;
    losecondition[1] = 0;
    losecondition[2] = 1;
    for (int i=3; i<40000; i++) {
        wincondition[i] = losecondition[i-1] + losecondition[i-2];
        losecondition[i] = wincondition[i-1] + wincondition[i-2];
    }


    int n;
    cin>>n;
    if (n>10)
        cout<<"["<<allcondition[n]<<','<<wincondition[n]<<"]"<<endl;
    else 
        cout<<"[]"<<endl;
    
    
    return 0;
}
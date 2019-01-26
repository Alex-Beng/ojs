#include <iostream>
#include <iomanip>

using namespace std;

int GetLayer(int num) {
    int t_layer = 1;
    while (2*t_layer*t_layer-1 < num) {
        t_layer++;
    }
    return t_layer;
}

int main() {
    int num;
    char ch;
    cin>>num>>ch;
    if (num == 0) {
        cout<<0<<endl;
        return 0;
    }
    else if (num == 1) {
        cout<<ch<<endl;
        cout<<0<<endl;
        return 0;
    }
    int layer = GetLayer(num);
    layer--;
    for (int i=0; i<layer; i++) {
        string t_line(i, ' ');
        cout<<t_line<<string(2*(layer-i)-1, ch)<<endl;
    }
    for (int i=1; i<layer; i++) {
        string t_line(layer-i-1, ' ');
        cout<<t_line<<string(2*i+1, ch)<<endl;
    }
    cout<<num-2*layer*layer+1<<endl;
    return 0;
}
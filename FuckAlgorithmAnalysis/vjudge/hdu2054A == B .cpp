#include <iostream>
#include <string>

using namespace std;

void change(string &str) {
    if (str.find('.') != string::npos) {
        int last = str.size();
        while (str[--last] == '0')
            str.erase(last, 1);
        if (str[last] == '.')
            str.erase(last, 1);
    }
    while (str[0] == '0') {
        if (str.length() != 1)
            str.erase(0, 1);
        else
            return;
    }
}
int main() {
    string a, b;
    while (cin >> a >> b) {
        change(a);
        change(b);
        if (a == b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

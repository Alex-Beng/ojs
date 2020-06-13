#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    string input_str;
    cin>>input_str;
    // cout<<input_str<<endl;

    int t_depth = 0;
    int max_depth = -1; 
    
    // 按表头分析
    for (int i=0; i<input_str.length(); i++) {
        if (input_str[i] == '(' ) {
            t_depth++;
        }
        else if (input_str[i] == ')') {
            t_depth--;
        }
        if (t_depth > max_depth) {
            max_depth = t_depth;
        }
    }
    cout<<max_depth<<endl<<max_depth;
    return 0;
}

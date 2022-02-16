with open("cao.cpp", "w") as f:
    f.write("""
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    switch (n) {""")
    for i in range(1000000):
        f.write(f'''
    case {i}:
        cout << "是{len(str(i))}位数" <<endl;''')
        base = 1
        base2str = {
            1:"个位数",
            10:"十位数",
            100:"百位数",
            1000:"千位数",
            10000:"万位数"
        }
        for b in range(len(str(i))):
            t = i//base % 10
            f.write(f'''
        cout << "{base2str[base]}是：{t}" << endl;''')
            base *= 10
        f.write(f'''
        cout << "倒过来是：{str(i)[::-1]}" << endl;
        break;
    ''')
            
            
    f.write("""
    }
    return 0;
}""")

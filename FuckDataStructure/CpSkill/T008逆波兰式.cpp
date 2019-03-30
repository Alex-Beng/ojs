#include <cstring>
#include <string>
#include <iostream>
using namespace std;

template<class T>
class Stack {
protected:
    T* data;
    int len;
    int max_size;
public:
    Stack(int size);

    void PushBack(T x);
    T Pop();
    T Top();
    bool IsEmpt() const;
};

int Priority[255];

int main(int argc, char const *argv[]) {
    Priority['('] = Priority[')'] = 1;
    Priority['+'] = Priority['-'] = 2;
    Priority['*'] = Priority['/'] = 3;

    Stack<char> operators_sk(2333);
    string ans = "";
    char raw_formula[2333];
    char t_c;
    cin>>raw_formula;

    int len = strlen(raw_formula);
    for (int i=0; i<len; i++) {
        t_c = raw_formula[i];
        if (t_c >= 'a' && t_c <= 'z') {// is num
            ans.push_back(t_c);
        }
        else if (t_c == '(') {
            operators_sk.PushBack(t_c);
        }
        else if (t_c == ')') {
            while(operators_sk.Top() != '(') {
                ans.push_back(operators_sk.Pop());
            }
            operators_sk.Pop();
        }
        else {// is operator
            if (operators_sk.IsEmpt()) {
                operators_sk.PushBack(t_c);
                continue;
            }

            if (Priority[t_c] <= Priority[operators_sk.Top()]) {
                ans.push_back(operators_sk.Pop());
                operators_sk.PushBack(t_c);
            }
            else {
                operators_sk.PushBack(t_c);
            }
        }
    }

    while (!operators_sk.IsEmpt()) {
        ans.push_back(operators_sk.Pop());
    }
    cout<<ans<<endl;

    return 0;
}




template<class T>
Stack<T>::Stack(int size) {
    data = new T[size];
    max_size = size;
    len = 0;
}

template<class T>
void Stack<T>::PushBack(T x) {
    data[len++] = x;
}

template<class T>
T Stack<T>::Pop() {
    return data[--len];
}

template<class T>
T Stack<T>::Top() {
    return data[len-1];
}

template<class T>
bool Stack<T>::IsEmpt() const {
    return len==0;
}



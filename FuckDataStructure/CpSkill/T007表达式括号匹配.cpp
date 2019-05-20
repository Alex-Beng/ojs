#include <cstring>
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

bool IsLeftBracket(char c) {
    if (c == '(' || c == '[' || c == '{') {
        return true;
    }
    else {
        return false;
    }
}

bool IsRightBracket(char c) {
    if (c == ')' || c == ']' || c == '}') {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char const *argv[]) {
    Stack<char> sk(2333);
    char raw_str[2333];
    char t_c;
    cin>>raw_str;
    for (int i=0; i<strlen(raw_str); i++) {
        t_c = raw_str[i];
        if (IsLeftBracket(t_c)) {
            sk.PushBack(t_c);
        }
        else if (IsRightBracket(t_c)) {
            if (t_c-sk.Top() == 1 || t_c-sk.Top() == 2) {
                sk.Pop();
            }
        }
    }
    if (sk.IsEmpt()) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    return 0;
}

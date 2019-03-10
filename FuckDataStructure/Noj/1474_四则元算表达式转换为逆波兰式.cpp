#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

template<class T>
class Stack {
private:
    T* data;
    int top;
    int max_size;
    bool resize(int new_size);
public:
    Stack(int size = 233);
    ~Stack();

    bool Push(T x);
    T Pop();
    T Top()const;
    bool Empty()const;
    int Size()const;
};

template<class T>
bool Stack<T>::resize(int new_size) {
    T* new_data = new T[new_size];
    if (new_data == NULL) {
        cerr<<"Fail to new array in: "<<__LINE__<<endl;
        return false;
    }
    for (int i=0; i<max_size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    return true;
}

template<class T>
Stack<T>::Stack(int size) {
    if (size > 0) {
        max_size = size;
        top = -1;
        data = new T[max_size];
        if (data == NULL) {
            cerr<<"Fail to new array in: "<<__LINE__<<endl;
            exit(1);
        }
    }
}

template<class T>
Stack<T>::~Stack() {
    delete[] data;
}

template<class T>
bool Stack<T>::Push(T x) {
    if (top+1 < max_size) {
        data[++top] = x;
        return true;
    }

    if (resize(2*max_size)) {
        max_size = 2*max_size;
        data[++top] = x;
        return true;
    }
    else {
        return false;
    }
}

template<class T>
T Stack<T>::Pop() {
    if (top >= 0) {
        return data[top--];
    }
    else {
        cerr<<"Fail to pop stack in: "<<__LINE__<<endl;
        exit(1);
    }
}

template<class T>
T Stack<T>::Top()const {
    return data[top];
}

template<class T>
bool Stack<T>::Empty()const {
    return (top == -1);
}

template<class T>
int Stack<T>::Size()const {
    return max_size;
}


bool IsNum(char t) {
    if (t == 'a' || t == 'b' || t == 'c') {
        return true;
    }
    else {
        return false;
    }
}

bool IsOpt(char t) {
    if (t=='+' || t=='-' || t=='*' || t=='/') {
        return true;
    }
    else {
        return false;
    }
}

short Priority[256];

int main(int argc, char const *argv[]) {
    // cout<<(int)'+'<<' '<<(int)'0'<<endl;
    if (IsNum('+')) {
        cout<<"Ya"<<endl;
    }
    Priority['('] = 1;
    Priority[')'] = 1;
    Priority['+'] = 2;
    Priority['-'] = 2;
    Priority['*'] = 3;
    Priority['/'] = 3;

    Stack<char> sk(233);
    char str[233];
    cin>>str;

    string output = "";

    for (int i=0; i<strlen(str); i++) {
        if (IsNum(str[i])) {
            // cout<<str[i]<<endl;
            output.push_back(str[i]);
        }
        else if (IsOpt(str[i])) {
            if (sk.Empty() || Priority[sk.Top()] < Priority[str[i]] ) {
                sk.Push(str[i]);
            }
            else if (!sk.Empty() && Priority[sk.Top()] >= Priority[str[i]]) {
                // cout<<str[i-1]<<' '<<str[i]<<endl;
                output.push_back(sk.Pop());
                sk.Push(str[i]);
            }
        }
        else if (str[i] == '(') {
            sk.Push(str[i]);
        }
        else if (str[i] == ')') {
            while (sk.Top() != '(') {
                output.push_back(sk.Pop());
            }
            sk.Pop();
        }
    }
    while (!sk.Empty()) {
        output.push_back(sk.Pop());
    }
    cout<<output<<endl;
    return 0;
}

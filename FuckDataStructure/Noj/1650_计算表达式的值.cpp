#include <cstring>

#include <iostream>
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
    void output()const;
};

template<class T>
void Stack<T>::output()const {

    for (int i=0; i<=top; i++) {
        cout<<data[i]<<' ';
    }
    cout<<endl;
}

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
    if (t >= '0' && t <= '9') {
        return true;
    }
    else {
        return false;
    }
}

int Compute(int n_1, int n_2, char sym) {
    switch (sym) {
        case '+':
            return n_1+n_2;    
        case '-':
            return n_1-n_2;
        case '*':
            return n_1*n_2;
        case '/':
            return n_1/n_2;
    };
}


short Priority[256];

int main(int argc, char const *argv[]) {
    Priority['('] = 1;
    Priority[')'] = 1;
    Priority['+'] = 2;
    Priority['-'] = 2;
    Priority['*'] = 3;
    Priority['/'] = 3;

    Stack<char> symbol_sk;
    Stack<int> num_sk;

    char raw_exp[2333];
    char t_c;

    cin>>raw_exp;

    for (int i=0; i<strlen(raw_exp); i++) {
        cout<<endl<<i<<endl;
        symbol_sk.output();
        num_sk.output();

        t_c = raw_exp[i];
        if (IsNum(t_c)) {
            t_c -= '0';
            num_sk.Push(t_c);
        }   
        else {// it is a symbol
            if (t_c == '(') {
                symbol_sk.Push(t_c);
            }
            else if (t_c == ')') {
                while (symbol_sk.Top() != '(') {
                    char comp_sym = symbol_sk.Pop();
                    int n2 = num_sk.Pop();
                    int n1 = num_sk.Pop();
                    num_sk.Push(Compute(n1, n2, comp_sym));

                    // cout<<"nmsl"<<symbol_sk.Top()<<endl;
                    // symbol_sk.Pop();
                }
                symbol_sk.Pop();
            }
            else if ( Priority[t_c] < Priority[symbol_sk.Top()] ) {
                // do compute
                char comp_sym = symbol_sk.Top();
                int n2 = num_sk.Pop();
                int n1 = num_sk.Pop();
                num_sk.Push(Compute(n1, n2, comp_sym));
            }
            else {
                symbol_sk.Push(t_c);
            }
        }
    }
    if (symbol_sk.Empty()) {
        cout<<num_sk.Top()<<endl;
    }
    else {
        // num_sk.output();
        // symbol_sk.output();
        char comp_sym = symbol_sk.Top();
        int n2 = num_sk.Pop();
        int n1 = num_sk.Pop();
        // cout<<n1<<' '<<n2<<' '<<comp_sym<<endl;
        cout<<Compute(n1, n2, comp_sym)<<endl;
    }
     
    return 0;
}

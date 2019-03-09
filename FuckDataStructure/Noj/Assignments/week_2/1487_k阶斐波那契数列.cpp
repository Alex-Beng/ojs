#include <iostream>
using namespace std;

template<class T>
class Queue {
private:
    T* data;
    int max_size;
    int head;
    int len;
    bool resize(int new_size);
public:
    Queue(int size = 233);
    ~Queue();
    T Pop();
    bool Push(T x);
    T Back()const;
    T Front()const;
    bool Empty()const;
    int Size()const;
    T GenerateNext();
    T Sum()const;
};

template<class T>
Queue<T>::Queue(int size) {
    max_size = size;
    data = new T[max_size];
    if (data == NULL) {
        cerr<<"Fail to new array in: "<<__FILE__<<" in: "<<__LINE__<<endl;
    }

    head = 0;
    len = 0;
}

template<class T>
Queue<T>::~Queue() {
    delete[] data; 
}

template<class T>
bool Queue<T>::resize(int new_size) {
    T* new_data = new T[new_size];
    if (new_data == NULL) {
        cout<<"Fail to new array in: "<<__FILE__<<" in: "<<__LINE__<<endl;
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
T Queue<T>::Pop() {
    T t = data[head++];
    head %= max_size;
    len--;
    return t;
}

template<class T>
bool Queue<T>::Push(T x) {
    if (len+1 <= max_size) {
        data[(head+len++)%max_size] = x;
    }
    else {
        return false;
    }
}

template<class T>
T Queue<T>::Back()const {
    return data[(head+len-1)%max_size];
}

template<class T>
T Queue<T>::Front()const {
    return data[head];
}

template<class T>
bool Queue<T>::Empty()const {
    return (len==0);
}

template<class T>
int Queue<T>::Size()const {
    return len;
}

template<class T>
T Queue<T>::GenerateNext() {
    T sum = this->Sum();
    this->Pop();
    this->Push(sum);
    return this->Back();
}

template<class T>
T Queue<T>::Sum()const {
    T sum = 0;
    for (int i=0; i<len; i++) {
        sum += data[(head+i)%max_size];
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    int k, max;
    cin>>k>>max;

    if (max == 0) {
        cout<<k-2<<endl
            <<0<<endl;
        return 0;
    }
    else if (max == 1) {
        cout<<k<<endl
            <<1<<endl;
        return 0;
    }

    Queue<long> qrq;
    for (int i=0; i<k-1; i++) {
        qrq.Push(0);
    }
    qrq.Push(1);

    long last_one;
    long t;
    int counter = k-1;
    while (1) {
        last_one = qrq.Back();
        // cout<<counter<<' '<<last_one<<endl;
        t = qrq.GenerateNext();
        if (last_one<=max && t>max) {
            cout<<counter<<endl
                <<last_one<<endl;
            break;
        }
        else {
            counter++;
            last_one = t;
        }
    }

    return 0;
}

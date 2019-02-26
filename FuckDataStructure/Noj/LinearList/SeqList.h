#ifndef SEQLIST_H
#define SEQLIST_H

#include "LinearList.h"

template<class T>
class SeqList:public LinearList<T> {
protected:
    T* data;
    int max_size;
    int last;
    void resize(int new_size);
public:
    SeqList(int size = 100);
    SeqList(SeqList<T>& L);
    ~SeqList();

    int Size() const;
    int Lenght() const;
    int Search(T& x) const;
    int Locate(int i) const;
    bool getData(int i, T& x) const;
    bool setData(int i, T& x);
    bool Insert(int i, T& x);
    bool Remove(int i, T& x);
    bool IsEmpty() const;
    bool IsFull() const;
    void Sort();
    void input();
    void output();
};   

template<typename T>
SeqList<T>::SeqList(int size) {
    if (size > 0) {
        max_size = size;
        last = -1;
        data = new T[max_size];
        if (data == NULL) {
        cerr << "fail to new in line: " << __LINE__ << endl;
            exit(1);
        }
    }
}

template<typename T>
SeqList<T>::SeqList(SeqList<T>& L) {
    max_size = L.Size();
    last = L.Lenght()-1;

    data = new T[max_size];
    if (data == NULL) {
        cerr << "fail to new in line: " << __LINE__ << endl;
        exit(1);
    }

    T t_value;
    for (int i = 1; i <= last+1; i++) {
        L.getData(i, t_value);
        data[i-1] = t_value;
    }
}

template<typename T>
SeqList<T>::~SeqList() {
    delete[] data;
}

template<typename T>
void SeqList<T>::resize(int new_size) {
    if (new_size <= 0) {
        cerr << "invalid new_size in line: " << __LINE__ << endl;
        return ;
    }
    if (new_size != max_size) {
        T* new_array = new T[new_size];
        if (new_array == NULL) {
            cerr << "fail to new in line: " << __LINE__ << endl;
            exit(1);
        }

        for (int i = 1; i <= last+1 && i <= new_size; i++) {
            new_array[i-1] = data[i-1];
        }

        delete[] data;
        data = new_array;
        max_size = new_size;
    }
}

template<typename T>
int SeqList<T>::Size()const {
    return last+1;
}

template<typename T>
int SeqList<T>::Lenght()const {
    return max_size;
}

template<typename T>
int SeqList<T>::Search(T& x)const {
    for (int i = 1; i <= last+1; i++) {
        if (data[i-1] == x) {
            return i;
        }
    }
    return 0;
}

template<typename T>
int SeqList<T>::Locate(int i)const {
    if (i >= 1 && i <= last+1) {
        return i-1;
    }
    else {
        return -1;
    }
}

template<typename T>
bool SeqList<T>::getData(int i, T& x)const {
    if (i >= 1 && i <= last+1) {
        x = data[i-1];
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
bool SeqList<T>::setData(int i, T& x) {
    if (i >= 1 && i <= last+1) {
        data[i-1] = x;
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
bool SeqList<T>::Insert(int i, T& x) {
    if (i >= 0 && i <= last+1 && last+2 <= max_size) {
        for (int j = last; j >= i; j--) {
            data[j+1] = data[j];
        }
        data[i] = x;
        last++;
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
bool SeqList<T>::Remove(int i, T& x) {
    if (i >= 1 && i <= last+1) {
        x = data[i-1];
        for (int j = i; j <= last; j++) {
            data[j-1] = data[j];
        }
        last--;;
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
bool SeqList<T>::IsEmpty()const {
    return last == -1;
}

template<typename T>
bool SeqList<T>::IsFull()const {
    return last == max_size-1;
}

template<typename T>
void SeqList<T>::Sort() {
    std::sort(data, data+last+1);
}


template<typename T>
void SeqList<T>::input() {
    cin>>last;
    last--;
    for (int i = 0; i <= last; i++) {
        cin>>data[i];
    }
}

template<typename T>
void SeqList<T>::output() {
    for (int i = 0; i <= last; i++) {
        cout<<data[i]<<' ';
    }
    cout<<endl;
}

#endif 
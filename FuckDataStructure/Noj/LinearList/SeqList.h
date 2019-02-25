#include "LinearList.h"

const int default_size = 100;

template<class T>
class SeqList: public LinearList<T> {
protected:
    T* data;
    int max_size;
    int last;
    void resize(int new_size);
public:
    SeqList(int size = default_size);
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
    void IsFull() const;
    void Sort();
    void input();
    void output();
    LinearList<T> operator==(LinearList<T>& L);
};   
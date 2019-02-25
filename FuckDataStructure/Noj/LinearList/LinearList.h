#include <bits/stdc++.h>
using namespace std;

// 抽象基类 LinearList
template<class T>
class LinearList {
public:
    LinearList();
    ~LinearList();

    virtual int Size() const = 0;           
    virtual int Lenght() const = 0;
    virtual int Search(T& x) const = 0;
    virtual int Locate(int i) const = 0;            // 注意是定位第i个元素在表中的序号（双向队列了解一下？）
    virtual bool getData(int i, T& x) const = 0;    // 注意仅对表进行访问不操作的都设置为const
    virtual bool setData(int i, T& x) = 0;
    virtual bool Insert(int i, T& x) = 0;
    virtual bool Remove(int i, T& x) = 0;
    virtual bool IsEmpty() const = 0;
    virtual void IsFull() const = 0;
    virtual void Sort() = 0;
    virtual void input() = 0;
    virtual void output() = 0;
    virtual LinearList<T> operator==(LinearList<T>& L) = 0;
};
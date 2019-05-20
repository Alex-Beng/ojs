#ifndef LINEARLIST_H
#define LINEARLIST_H

#include <bits/stdc++.h>
using namespace std;

// 抽象基类 LinearList
template<class T>
class LinearList {
public:
    LinearList(){}
    ~LinearList(){}

    virtual int Size() const = 0;                   // 注意 Size 是最大容纳空间 
    virtual int Length() const = 0;                 // 而 Lenght 是当前使用的空间（即当前表长）
    virtual int Search(T& x) const = 0;             // 注意从类外操作的第一个元素其实是从0开始
    virtual int Locate(int i) const = 0;            // 注意是定位第i个元素（不是从0开始的鸭，从1开始）在表中的序号（双向队列了解一下？）
    virtual bool getData(int i, T& x) const = 0;    // 注意仅对表进行访问不操作的都设置为const
    virtual bool setData(int i, T& x) = 0;
    virtual bool Insert(int i, T& x) = 0;           // 注意插入到第i位位置后面，i取值范围为 [0, last+1]
    virtual bool Remove(int i, T& x) = 0;           // 删除只能取到 [1, last+1]
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual void Sort() = 0;
    virtual void input() = 0;
    virtual void output() = 0;
};

#endif
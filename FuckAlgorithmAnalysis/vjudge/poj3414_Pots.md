# poj 3414 Pots 题解
[题目链接](https://vjudge.net/problem/POJ-3414)

知识点：记忆化bfs，手写队列，class as map's key(我这种憨批做法时)

知识点与hud1495类似，但是需要记忆路径，所以需要自己手写一个简易队列（还好这种简易数据结构还会写）。


## 坑：

### status结构体的重载运算符

```cpp
    // for map
    bool operator<(const status& that) const {
        //! 状态只与AB有关
        int this_key = cB*1000 + cA;
        int that_key = that.cB*1000 + that.cA;
        return this_key<that_key;
    }
```
为了能够```std::map<status, int> cost```，对status重载了一个<比较运算符（其他比较例如>, !=都能用布尔运算推出来）

然后第一次非常憨批的把 prev key 和 op 都放进了用于判断的量里面。实际上搜索状态只与A、B当前的水量有关。

### ### ctrl cv时不认真改

```cpp
    if (t_s.cB>0 && t_s.cA<A) {//! 第一次直接赋值，第二次才发现没改这个if
        int t_water = min((A-t_s.cA), t_s.cB);//! 第一次发现了这里
        t_s.cB -= t_water;
        t_s.cA += t_water;
        t_s.prev = t_idx;
        t_s.op = 5;
        if (!cost[t_s]) {
            cost[t_s] = t_cost + 1;
            st_qrq[qrq_tail_idx++] = t_s;
        }
        t_s.cB += t_water;
        t_s.cA -= t_water;
    }
```

老问题了，就离谱，在同一个坑里摔两次。


## 学到了啥：

### 友元重载输入输出

DEFINE

友元：C++提供的一种破坏数据封装和数据隐藏的机制。

友元函数
友元函数是在类声明中由关键字friend修饰说明的非成员函数，在它的函数体中能够通过对象名访问 private 和 protected成员。
作用：增加灵活性，使程序员可以在封装和快速性方面做合理选择。
访问对象中的成员必须通过对象名。

```cpp
// 这样就可以访问output和s的private和protected成员
friend ostream &operator<<( ostream &output, 
                                       const status &s )
{ 
    output << "A: " << s.cA << " B: " << s.cB << " prev: "<<s.prev << " op: "<<s.op;
    return output;            
}

friend istream &operator>>( istream  &input, Distance &D )
{ 
    input >> D.feet >> D.inches;
    return input;            
}
```


## 后记

4.11 樱花🌸赛，就当给自己放一天假8，有时候还是要放过自己。

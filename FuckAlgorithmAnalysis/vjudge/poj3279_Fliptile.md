# poj 3279 filptile 题解


[题目链接](https://vjudge.net/problem/POJ-3279)


知识点：状态压缩，暴力搜索

思路：
```
  x
x x x
  x
```
一个块状态 = 自己原状态 + （包括自己的）周围五个操作。

枚举第一行所有操作后，(r, c)的黑色块仅能通过(r+1, c)的翻转操作翻白。

最后，仅需确定最后一行全为白，即可判断有无解。

## 坑：

### 粗心(老问题了！)

```cpp
int diff[4][2] = {//! 5->4
    {0, 0},
    {-1, 0},
    {0, -1},
    {0, 1},
};
```
最初写成[5][2]，然后导致自己会被多计一次，导致get_color得到完全不同的颜色。


### 复制代码不认真改(老问题了！)

```cpp
    int t_ans = 0;
    for (int tr=0; tr<m; tr++) {//! tr=1
        for (int tc=0; tc<n; tc++) {
            t_ans += curr_ops[tr][tc];
        }
    }

```

### 更新最优解判断条件

```cpp
    if (t_ass < answ && t_ass != -1) {//!
        // cout<<t_ass<<endl;
        // out_res(curr_ops);
        
        answ = t_ass;
        memcpy(answ_ops, curr_ops, sizeof(curr_ops));
    }

```

search()返回-1作为无解标志，然后写个<，真有你的。

### 输出无解条件
```cpp
    if (answ == -1 || answ == 2147483647) {//!
        cout<<"IMPOSSIBLE"<<endl;
    }
```

真有你的，写个-1无解

## 学到了啥

### cstring 内存操作

```cpp
memset(void *_Dst,int _Val,size_t _Size);

memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _Size)
```

## 后记

别摸了别摸了，摸到下午2点才A，太垃圾了。

以后期望用时最多2小时可好？
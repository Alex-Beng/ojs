#
# @lc app=leetcode.cn id=622 lang=python3
#
# [622] 设计循环队列
#

# @lc code=start
class MyCircularQueue:

    def __init__(self, k: int):
        self.n = k
        self.que = [0]*k
        self.head = 0
        self.tail = 0
        self.cap = 0

    def enQueue(self, value: int) -> bool:
        if self.cap == self.n:
            return False
        self.que[self.tail] = value
        self.tail += 1
        self.tail %= self.n
        self.cap += 1
        return True

    def deQueue(self) -> bool:
        if self.cap == 0:
            return False
        self.head += 1
        self.head %= self.n
        self.cap -= 1
        return True

    def Front(self) -> int:
        return -1 if self.cap == 0 else self.que[self.head]

    def Rear(self) -> int:
        return -1 if self.cap == 0 else self.que[self.tail-1]

    def isEmpty(self) -> bool:
        return self.cap==0

    def isFull(self) -> bool:
        return self.cap==self.n

# @lc code=end


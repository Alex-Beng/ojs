#
# @lc app=leetcode.cn id=225 lang=python3
#
# [225] 用队列实现栈
#

# @lc code=start

class queue:
    def __init__(self):
        self.q = []
    def push(self, n):
        self.q.append(n)
    def pop(self):
        t = self.q[0]
        del self.q[0]
        return t
    def size(self):
        return len(self.q)
    def top(self):
        return self.q[0]

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = queue()
        self.q2 = queue()
        


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.push(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while self.q1.size() != 1:
            t = self.q1.pop()
            self.q2.push(t)
        self.q1, self.q2 = self.q2, self.q1
        ans = self.q2.top()
        self.q2.pop()
        return ans

    def top(self) -> int:
        """
        Get the top element.
        """
        while self.q1.size() != 1:
            t = self.q1.pop()
            self.q2.push(t)
        self.q1, self.q2 = self.q2, self.q1
        t = self.q2.pop()
        self.q1.push(t)
        return t


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.q1.size()==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
# @lc code=end


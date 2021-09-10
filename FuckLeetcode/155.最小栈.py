#
# @lc app=leetcode.cn id=155 lang=python3
#
# [155] 最小栈
#

# @lc code=start
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = []
        self.n = 0

    def push(self, val: int) -> None:
        if self.n < len(self.stack):
            self.stack[self.n] = val
        else:
            self.stack.append(val)
            self.min_stack.append(0)
        
        if self.n - 1 >= 0:
            self.min_stack[self.n] = min(self.min_stack[self.n-1], val)
        else:
            self.min_stack[self.n] = val
        
        self.n += 1


    def pop(self) -> None:
        self.n -= 1
        return self.stack[self.n]
        

    def top(self) -> int:
        return self.stack[self.n-1]


    def getMin(self) -> int:
        return self.min_stack[self.n-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end


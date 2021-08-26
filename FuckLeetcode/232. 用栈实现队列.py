class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.sk1 = [0]*233
        self.sk1_len = 0
        self.sk2 = [0]*233
        self.sk2_len = 0


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.sk1[self.sk1_len] = x
        self.sk1_len += 1


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        for i in range(self.sk1_len-1, -1, -1):
            pop_val = self.sk1[i]
            self.sk1_len -= 1

            self.sk2[self.sk2_len] = pop_val
            self.sk2_len += 1
        
        res = self.sk2[self.sk2_len-1]
        self.sk2_len -= 1

        for i in range(self.sk2_len-1, -1, -1):
            pop_val = self.sk2[i]
            self.sk2_len -= 1

            self.sk1[self.sk1_len] = pop_val
            self.sk1_len += 1
        return res
            


    def peek(self) -> int:
        """
        Get the front element.
        """
        for i in range(self.sk1_len-1, -1, -1):
            pop_val = self.sk1[i]
            self.sk1_len -= 1

            self.sk2[self.sk2_len] = pop_val
            self.sk2_len += 1
        
        res = self.sk2[self.sk2_len-1]
        # self.sk2_len -= 1

        for i in range(self.sk2_len-1, -1, -1):
            pop_val = self.sk2[i]
            self.sk2_len -= 1

            self.sk1[self.sk1_len] = pop_val
            self.sk1_len += 1
        return res



    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return self.sk1_len==0



# Your MyQueue object will be instantiated and called as such:
obj = MyQueue()
obj.push(1)
obj.push(2)
param_2 = obj.pop()
param_3 = obj.peek()
param_4 = obj.empty()
print(param_2, param_3, param_4)
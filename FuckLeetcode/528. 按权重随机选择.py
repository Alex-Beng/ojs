import random

class Solution:

    def __init__(self, w: [int]):
        self.n = len(w)
        self.total = sum(w)
        self.pre_sum = [w[0]]*self.n
        for i in range(1, self.n):
            self.pre_sum[i] = self.pre_sum[i-1]+w[i]
        print(self.pre_sum)

    def pickIndex(self) -> int:
        t = random.randint(1, self.total)

        L = 0
        R = self.n-1
        ans = -1
        while L<=R:
            m = (L+R)//2
            if t<=self.pre_sum[m]:
                ans = m
                R = m-1
            else:
                L = m+1
        # print(t, ans)
        return ans



# Your Solution object will be instantiated and called as such:
obj = Solution(
    [1,]
)
for i in range(8):
    param_1 = obj.pickIndex()
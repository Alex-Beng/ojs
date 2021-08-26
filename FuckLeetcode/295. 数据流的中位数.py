class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.n = 0
        self.nums = []


    def addNum(self, num: int) -> None:
        if not self.n:
            self.nums.append(num)
            self.n += 1
            return

        l = 0
        r = self.n-1
        insert_idx = self.n
        while l<=r:
            m = (l+r)//2
            if self.nums[m]>=num:
                insert_idx = m
                r = m-1
            else:
                l = m+1
        # print(insert_idx)

        self.nums.insert(insert_idx, num)
        self.n += 1
        # print(self.nums)
                


    def findMedian(self) -> float:
        # print(self.nums)
        m = self.n//2
        if self.n&1:
            return self.nums[m]
        else:
            return (self.nums[m]+self.nums[m-1])/2

s = MedianFinder()
s.addNum(1)
s.addNum(0)
print(s.findMedian())
s.addNum(3)
print(s.findMedian())
s.addNum(2)
s.addNum(100)
print(s.findMedian())


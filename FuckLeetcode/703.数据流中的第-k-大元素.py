#
# @lc app=leetcode.cn id=703 lang=python3
#
# [703] 数据流中的第 K 大元素
#

# @lc code=start
class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.nums = sorted(nums)
        self.k = k

    def add(self, val: int) -> int:
        L = 0
        R = len(self.nums)-1
        while L<=R:
            m = (L+R)//2
            if self.nums[m] <= val:
                L = m+1
            else:
                R = m-1
        self.nums.insert(L, val)
        return self.nums[-self.k]

# @lc code=end
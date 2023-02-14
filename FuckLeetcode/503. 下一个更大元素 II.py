from typing import List

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        ori_n = len(nums)
        nums = nums + nums
        n = len(nums)
        # print(nums)
        next_big = [-1] * n
        sk = []

        for i, n in enumerate(nums):
            # print(sk)
            while len(sk) and n > nums[sk[-1]]:
                next_big[sk[-1]] = i
                del sk[-1]
            sk.append(i)
        ans = [nums[i] if i!=-1 else -1 for i in next_big[:ori_n]]
        return ans
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        next_big = [-1] * n
        sk = []

        # 并不需要“拉直”，可以直接循环多次
        for i in range(2*n):
            i = i % n
            num = nums[i]

            while len(sk) and num > nums[sk[-1]]:
                next_big[sk[-1]] = i
                del sk[-1]
            sk.append(i)
        ans = [nums[i] if i!=-1 else -1 for i in next_big]
        return ans
s = Solution()
r = s.nextGreaterElements(
    [1,2,1]
)
print(r)
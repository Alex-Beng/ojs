class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        num2times = dict()
        ans = 0
        for n in nums:
            if n in num2times:
                ans += num2times[n]
                num2times[n] += 1
            else:
                num2times[n] = 1
        return ans
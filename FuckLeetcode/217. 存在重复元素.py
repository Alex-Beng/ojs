class Solution:
    def containsDuplicate(self, nums: [int]) -> bool:
        n = len(nums)
        appear = dict()
        for t in nums:
            if t in appear:
                appear[t] += 1
            else:
                appear[t] = 1
        if max(appear.values()) >= 2:
            return True
        else:
            return False
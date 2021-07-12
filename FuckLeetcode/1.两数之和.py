class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        bins = dict()
        bins_idx = dict()
        for idx,num in enumerate(nums):
            bins[num] = 1
            bins_idx[num] = idx
        ans = []
        for idx,num in enumerate(nums):
            if (target-num) in bins and bins_idx[target-num]!=idx:
                ans.append(idx)
                ans.append(bins_idx[target-num])
                break
        return ans
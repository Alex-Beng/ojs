class Solution:
    def threeSum(self, nums: [int]) -> [[int]]:
        n = len(nums)
        num2idx = dict()
        for idx,num in enumerate(nums):
            if num in num2idx:
                num2idx[num].append(idx)
            else:
                num2idx[num] = [idx]

        ans = set()
        for i in range(n):
            for j in range(i+1, n):
                n1 = nums[i]
                n2 = nums[j]
                n3 = -n1-n2
                if n3 in num2idx:
                    idxes = num2idx[n3]
                    if idxes[-1] > j:
                        ans.add(tuple(sorted([n1, n2, n3])))                        
                else:
                    continue
        return [list(i) for i in ans]
s = Solution()
print(s.threeSum(
    [-1,0,1,2,-1,-4]
    # [0,0]
)
)
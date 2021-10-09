class Solution:
    def countSmaller(self, nums: [int]) -> [int]:
        n = len(nums)
        count = [0]*n
        tnums = [nums[-1]]
        for i in range(n-2, -1, -1):
            t = nums[i]
            l = 0
            r = len(tnums)-1
            tans = len(tnums)
            while l<=r:
                m = (l+r)//2
                if t <= tnums[m]:
                    r = m-1
                    tans = m
                else:
                    l = m+1
            tnums.insert(tans, t)
            # print(tnums, l, r, tans)
            count[i] = tans
        return count
s = Solution()
r = s.countSmaller(
    # [5,2,6,1]
    [-1,-1]
)
print(r)
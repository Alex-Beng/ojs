class Solution:
    def threeSumClosest(self, nums: [int], target: int) -> int:
        '''
        n^2log(n)
        '''
        n = len(nums)
        nums.sort()
        print(nums)
        min_dist = float('inf')
        ans = float('inf')
        for i in range(n):
            for j in range(i+1, n):
                n1 = nums[i]
                n2 = nums[j]
                n3 = target-n1-n2
                # print(i, j)
                L = j+1
                R = n
                # print(L, R)
                while L<R:
                    m = L + (R-L)//2
                    if nums[m]<n3:
                        L = m+1
                    else:
                        R = m
                # print(L)
                if L==n:
                    L = n-1
                    if abs(nums[L]-n3) < min_dist and L!=j:
                        min_dist = abs(nums[L]-n3)
                        ans = n1+n2+nums[L]
                    # print(n1, n2, nums[L], ans)
                    continue

                if abs(nums[L]-n3) < min_dist:
                    min_dist = abs(nums[L]-n3)
                    ans = n1+n2+nums[L]
                if L-1>j and abs(nums[L-1]-n3) < min_dist:
                    L -= 1
                    min_dist = abs(nums[L]-n3)
                    ans = n1+n2+nums[L]
                # print(ans)
        return ans
    def threeSumClosest(self, nums: [int], target: int) -> int:
        '''
        n^2
        '''
        nums.sort()
        n = len(nums)
        min_dist = float('inf')
        ans = 0
        for i in range(n-2):
            n1 = nums[i]
            L = i+1
            R = n-1
            while L<R:
                # print(i, L, R)
                n2 = nums[L]
                n3 = nums[R]
                t_s = n1+n2+n3

                if abs(target-t_s) < min_dist:
                    min_dist = abs(target-t_s)
                    ans = t_s
                    
                if t_s > target:
                    R -= 1
                elif t_s < target:
                    L += 1
                else:
                    return target
        return ans

s = Solution()
print(s.threeSumClosest(
    [-1,2,1,-4], 1
    # [-1,0,1,1,55], 3
    # [-1,2,1,-4], 1
))
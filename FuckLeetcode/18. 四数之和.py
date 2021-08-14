class Solution:
    def fourSum(self, nums: [int], target: int) -> [[int]]:
        n = len(nums)
        for i in range(n):
            nums[i] = (nums[i], i)
        nums.sort(key=lambda k: k[0])

        ans = set()
        for i in range(n-3):
            for j in range(i+1, n-2):
                n1 = nums[i][0]
                n2 = nums[j][0]
                L = j+1
                R = n-1
                while L<R:
                    n3 = nums[L][0]
                    n4 = nums[R][0]
                    t_s = n1+n2+n3+n4
                    if t_s < target:
                        L += 1
                    elif t_s > target:
                        R -= 1
                    else:
                        ans.add((n1, n2, n3, n4))
                        L += 1
        # print(ans)
        ans = [list(i) for i in ans]
        # print(ans)
        return ans
s = Solution()
s.fourSum(
    # [1,0,-1,0,-2,2], 0
    [-3,-1,0,2,4,5], 0

)
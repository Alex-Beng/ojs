class Solution:
    def nthUglyNumber(self, n: int) -> int:
        u_nums = [1]*(n+1)

        p_2 = p_3 = p_5 = 1
        for i in range(2, n+1):
            
            t2 = u_nums[p_2]*2
            t3 = u_nums[p_3]*3
            t5 = u_nums[p_5]*5
            u_nums[i] = min(t2, t3, t5)
            if u_nums[i] == t2:
                p_2 += 1
            if u_nums[i] == t3:
                p_3 += 1
            if u_nums[i] == t5:
                p_5 += 1
            # print(u_nums, p_2, p_3, p_5)
        return u_nums[n]
s = Solution()
print(s.nthUglyNumber(10))
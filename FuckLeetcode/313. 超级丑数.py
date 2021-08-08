class Solution:
    def nthSuperUglyNumber(self, n: int, primes) -> int:
        pn = len(primes)

        u_nums = [1]
        p_pnt = [0]*pn

        for i in range(n):
            candidates = [ primes[i]*u_nums[p_pnt[i]] for i in range(pn) ]
            next_pnum = min(candidates)
            u_nums.append(next_pnum)
            for i in range(pn):
                if next_pnum == candidates[i]:
                    p_pnt[i] += 1
            print(u_nums)
        
        return u_nums[n-1]
s = Solution()
print(s.nthSuperUglyNumber(
    12,
    [2,7,13,19]
))
class Solution:
    def numRescueBoats(self, people: [int], limit: int) -> int:
        n = len(people)

        people.sort()
        l = 0
        r = n-1

        ans = 0
        while l<r:
            if people[r]+people[l]<=limit:
                r -= 1
                l += 1
                ans += 1
            else:
                r -= 1
                ans += 1

        if l==r:    
            ans += 1
        # print(ans)
        return ans
s = Solution()
s.numRescueBoats(
    # [1,2, 2,3], 3
    # [1,2,],3
     [3,5,3,4], 5
)
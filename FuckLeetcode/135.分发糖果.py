class Solution:
    def candy(self, ratings: [int]) -> int:
        n = len(ratings)
        candy = [1]*n
        lc = [0]*n
        rc = [0]*n

        for i in range(1, n):
            if ratings[i-1]<ratings[i]:
                lc[i] = lc[i-1]+1
        for i in range(n-2, -1, -1):
            if ratings[i]>ratings[i+1]:
                rc[i] = rc[i+1]+1
        for i in range(n):
            candy[i] += max(lc[i], rc[i])
        # print(candy, lc, rc)
        return sum(candy)
s = Solution()
r = s.candy(
# [1,2,87,87,87,2,1]
[1,2,3]
)
print(r)
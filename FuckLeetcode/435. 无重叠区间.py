class Solution:
    def eraseOverlapIntervals(self, intervals: [[int]]) -> int:
        n = len(intervals)

        intervals.sort(key=lambda k:k[1])
        r = intervals[0][1]
        ans = 1
        for i in range(1, n):
            if intervals[i][0] >= r:
                r = intervals[i][1]
                ans += 1
        return n-ans
s = Solution()
s.eraseOverlapIntervals(
    [[1,2],[2,3],[3,4],[1,3]]
)
class Solution:
    def corpFlightBookings(self, bookings: [[int]], n: int) -> [int]:
        ans = [0]*(n+2)
        for b in bookings:
            l, r, d = b
            ans[l] += d
            ans[r+1] -= d
        for i in range(1, n+1):
            ans[i] += ans[i-1]
        return ans[1:-1]
s = Solution()
print(s.corpFlightBookings(
    # [[1,2,10],[1,2,20],[1,2,25]],5
    [[1,2,10],[2,3,20],[2,5,25]], 5
))
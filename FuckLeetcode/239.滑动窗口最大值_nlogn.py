#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#

# @lc code=start
from queue import PriorityQueue
class Solution:
    def maxSlidingWindow(self, nums: [int], k: int) -> [int]:

        que = PriorityQueue()
        for i,n in enumerate(nums[:k]):
            que.put((-n,i))

        ans = [-que.queue[0][0]]
        n = len(nums)
        for i in range(k, n):
            an = nums[i]
            que.put((-an,i))
            while que.queue[0][1] <= i-k:
                que.get()
            ans.append(-que.queue[0][0])
        return ans

# @lc code=end
s = Solution()
r = s.maxSlidingWindow(
     [1,3,-1,-3,5,3,6,7], 3
    # [1,3,1,2,0,5],3
)
print(r)
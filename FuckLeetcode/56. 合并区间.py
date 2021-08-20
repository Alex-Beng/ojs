from copy import deepcopy

class Solution:
    def merge(self, intervals: [[int]]) -> [[int]]:
        intervals.sort(key=lambda k:k[0])
        ans = []
        ans.append(deepcopy(intervals[0]))
        for i in range(1, len(intervals)):
            curr_inter = intervals[i]
            curr_head = curr_inter[0]
            last_inter = ans[-1]
            if curr_head>=last_inter[0] and curr_head<=last_inter[1]: # can merge
                last_inter[1] = max(curr_inter[1], last_inter[1])
            else:
                ans.append(deepcopy(curr_inter))
        # print(ans)
        return ans
s = Solution()
s.merge(
    # [[1,3],[2,6],[8,10],[15,18]]
    [[1,4],[4,5]]
)
                
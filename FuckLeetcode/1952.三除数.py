#
# @lc app=leetcode.cn id=1952 lang=python3
#
# [1952] 三除数
#

# @lc code=start
class Solution:
    def isThree(self, n: int) -> bool:
        return sum([1 for i in range(2,n) if n%i==0])==1
# @lc code=end


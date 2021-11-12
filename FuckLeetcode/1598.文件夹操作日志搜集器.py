#
# @lc app=leetcode.cn id=1598 lang=python3
#
# [1598] 文件夹操作日志搜集器
#

# @lc code=start
class Solution:
    def minOperations(self, logs: [str]) -> int:
        sk = []
        for dir in logs:
            if dir=='./':
                continue
            elif dir=='../':
                if len(sk):
                    sk.pop()
            else:
                sk.append(dir)
        return len(sk)
# @lc code=end
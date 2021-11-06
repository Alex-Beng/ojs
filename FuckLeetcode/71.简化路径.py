#
# @lc app=leetcode.cn id=71 lang=python3
#
# [71] 简化路径
#

# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        dirs = path.split('/')
        res = []
        for dir in dirs:
            if dir=='' or dir=='.':
                continue
            elif dir=='..':
                if len(res):
                    del res[-1]
            else:
                res.append(dir)
        return '/'+'/'.join(res)
# @lc code=end
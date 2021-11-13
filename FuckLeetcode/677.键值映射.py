#
# @lc app=leetcode.cn id=677 lang=python3
#
# [677] 键值映射
#

# @lc code=start
import re
class MapSum:

    def __init__(self):
        self.k2v = dict()

    def insert(self, key: str, val: int) -> None:
        self.k2v[key] = val

    def sum(self, prefix: str) -> int:
        print(self.k2v)
        return sum([self.k2v[k] for k in self.k2v.keys() if re.match(f"{prefix}.*", k)])

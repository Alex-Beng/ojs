#
# @lc app=leetcode.cn id=705 lang=python3
#
# [705] 设计哈希集合
#

# @lc code=start
class MyHashSet:

    def __init__(self):
        self.keys = []

    def add(self, key: int) -> None:
        if self.contains(key):
            return
        n = len(self.keys)
        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            t = self.keys[m]
            if t <= key:
                L = m+1
            else:
                R = m-1
        self.keys.insert(L, key)

    def remove(self, key: int) -> None:
        if not self.contains(key):
            return
        n = len(self.keys)
        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            t = self.keys[m]
            if t==key:
                del self.keys[m]
                return
            elif t<key:
                L = m+1
            elif t>key:
                R = m-1

    def contains(self, key: int) -> bool:
        n = len(self.keys)
        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            t = self.keys[m]
            if t==key:
                return True
            elif t<key:
                L = m+1
            elif t>key:
                R = m-1
        return False

# @lc code=end


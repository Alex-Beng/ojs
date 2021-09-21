#
# @lc app=leetcode.cn id=841 lang=python3
#
# [841] 钥匙和房间
#

# @lc code=start
from queue import Queue
class Solution:
    def canVisitAllRooms(self, rooms: [[int]]) -> bool:
        n = len(rooms)
        been = [0]*n
        
        q = Queue()
        
        q.put(0)
        # been[0] = 1
        while not q.empty():
            nd = q.get()
            been[nd] = 1

            for to in rooms[nd]: 
                if not been[to]:
                    q.put(to)
        for b in been:
            if not b:
                return False
        return True
# @lc code=end


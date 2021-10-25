#
# @lc app=leetcode.cn id=690 lang=python3
#
# [690] 员工的重要性
#

class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

# @lc code=start

class Solution:
    def getImportance(self, employees: ['Employee'], id: int) -> int:
        n = len(employees)
        que = [id]
        id2info = dict()
        for e in employees:
            id = e.id
            imp = e.importance
            sub = e.subordinates
            id2info[id] = (imp, sub)

        ans = 0
        while len(que):
            id = que[0]
            del que[0]
            ans += id2info[id][0]
            for s in id2info[id][1]:
                que.append(s)
        return ans
        
# @lc code=end


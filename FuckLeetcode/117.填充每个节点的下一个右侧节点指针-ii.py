#
# @lc app=leetcode.cn id=117 lang=python3
#
# [117] 填充每个节点的下一个右侧节点指针 II
#

class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

# @lc code=start

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        def connect(nodes: [Node]):
            n = len(nodes)
            if not len(nodes):
                return 
            nnodes = []
            for i,nd in enumerate(nodes):
                if i+1 < n:
                    nd.next = nodes[i+1]
                if nd.left is not None:
                    nnodes.append(nd.left)
                if nd.right is not None:
                    nnodes.append(nd.right)
            connect(nnodes)
        if root is None:
            return None
        connect([root])
        return root
# @lc code=end


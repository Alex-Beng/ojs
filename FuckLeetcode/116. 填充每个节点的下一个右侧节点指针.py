
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root
        layer = [root]
        while len(layer) != 0:
            new_l = []
            n = len(layer)
            for i in range(n):
                if i==n-1:
                    layer[i].next = None
                else:
                    layer[i].next = layer[i+1]

                if layer[i].left is not None:
                    new_l.append(layer[i].left)
                    new_l.append(layer[i].right)
            layer = new_l
        return root

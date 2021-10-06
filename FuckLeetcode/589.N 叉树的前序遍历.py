class Solution:
    def preorder(self, root: 'Node') -> [int]:
        ans = []
        def pord(node: 'Node'):
            if node is None:
                return
            ans.append(node.val)
            if node.children is None:
                return
            for c in node.children:
                pord(c)
        pord(root)
        return ans
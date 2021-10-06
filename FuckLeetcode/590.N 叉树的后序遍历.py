class Solution:
    def postorder(self, root: 'Node') -> [int]:
        ans = []
        def pord(node: 'Node'):
            if node is None:
                return
            
            if node.children is None:
                return
            for c in node.children:
                pord(c)
            ans.append(node.val)
        pord(root)
        return ans
#
# @lc app=leetcode.cn id=297 lang=python3
#
# [297] 二叉树的序列化与反序列化
#

from util import TreeNode

# @lc code=start

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        ans = []
        def layerOrder(nodes: [TreeNode]):
            nnodes = []
            for nd in nodes:
                if nd is None:
                    ans.append('None')
                    continue
                ans.append(f'{nd.val}')
                nnodes.append(nd.left)
                nnodes.append(nd.right)
            if len(nnodes):
                layerOrder(nnodes)
        layerOrder([root])

        return ','.join(ans)
        
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def val2node(n: str):
            if n != 'None':
                return TreeNode(int(n))
            else:
                return None
        
        ans = data.split(',')
        head = val2node(ans[0])
        cnt = 1
        
        def layerOrder(nodes: [TreeNode]):
            nonlocal cnt
            nnodes = []
            for nd in nodes:
                if nd is None:
                    continue
                nd.left = val2node(ans[cnt])
                cnt += 1
                nd.right = val2node(ans[cnt])
                cnt += 1
                nnodes.append(nd.left)
                nnodes.append(nd.right)
            if len(nnodes):
                layerOrder(nnodes)
        layerOrder([head])
        return head
            
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
# @lc code=end




#
# @lc app=leetcode.cn id=257 lang=python3
#
# [257] 二叉树的所有路径
#
from util import TreeNode
# @lc code=start
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> [str]:
        ans = []
        def dfs(node: TreeNode, path: [int]):
            if node is None:
                return 
            if node.left is None and node.right is None:
                ans.append(tuple(path+[str(node.val)]))
                return
            dfs(node.left, path+[str(node.val)])
            dfs(node.right, path+[str(node.val)])
            return 
        dfs(root, [])
        return ["->".join(p) for p in ans]
            
            
# @lc code=end

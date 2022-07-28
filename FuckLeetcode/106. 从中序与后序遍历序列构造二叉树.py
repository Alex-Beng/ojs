
from util import TreeNode
class Solution:
    def buildTree(self, inorder: [int], postorder: [int]) -> TreeNode:
        def b_t(i_b, i_e, p_b, p_e) -> TreeNode:
            # print(i_b, i_e, p_b, p_e)

            if i_b == i_e:
                return TreeNode(inorder[i_b])
            mid_val = postorder[p_e]
            mid_node = TreeNode(mid_val)
            left_num = inorder.index(mid_val) - i_b
            righ_num = i_e - i_b - left_num 
            # print(left_num, righ_num)
            if left_num > 0:
                mid_node.left = b_t(
                    i_b, i_b+left_num-1, 
                    p_b, p_b+left_num-1)
            if righ_num > 0:
                mid_node.right = b_t(
                    i_b+left_num+1, i_e, 
                    p_b+left_num, p_e-1)
            return mid_node

        n = len(inorder)
        return b_t(0, n-1, 0, n-1)

s = Solution()
s.buildTree([2, 1], [2, 1])
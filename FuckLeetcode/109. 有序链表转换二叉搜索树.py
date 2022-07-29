from util import *

class Solution:
    def sortedListToBST(self, head):
        array = []
        t_ptr = head
        while t_ptr is not None:
            array.append(t_ptr.val)
            t_ptr = t_ptr.next
        n = len(array)
        def b_t(b, e):
            if b>e:
                return None
            if b==e:
                return TreeNode(array[b])
            
            mid = (b+e)//2
            mid_node = TreeNode(array[mid])
            
            mid_node.left = b_t(b, mid-1)
            mid_node.right = b_t(mid+1, e)
            return mid_node
        return b_t(0, n-1)

lk = make_link([-10,-3,0,5,9])
s = Solution()
s.sortedListToBST(lk)
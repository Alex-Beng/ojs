from util import *


from typing import List, Optional
from copy import deepcopy

class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(node: Optional[TreeNode], tnum: int) -> int:
            nonlocal ans
            tnum = tnum * 10 + node.val
            if node.left is None and node.right is None:
                ans += tnum
            else:
                if node.left is not None:
                    dfs(node.left, tnum)
                if node.right is not None:
                    dfs(node.right, tnum) 
        dfs(root, 0)
        return ans

s = Solution()
r = s.sumNumbers(
    # make_tree(' [1,2,3]')   
    make_tree(' [0,1]')
)
print(r)
# LINK LIST
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def make_link(nums):
    if len(nums)==0:
        return None
    ya = []
    for i in nums:
        ya.append(ListNode(i))
    for i in range(0, len(ya)-1):
        ya[i].next = ya[i+1]
    return ya[0]


def print_link(t_ptr):
    while t_ptr is not None:
        print(t_ptr.val, end=' ')
        t_ptr = t_ptr.next
    print()

# TREE
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def make_tree(assign: str):
    assign = assign.replace('null', 'None')
    vals = eval(assign.split('=')[-1])
    def make_tree_helper(vals):
        # 从层序遍历的数组构造二叉树
        if len(vals) == 0:
            return None
        ya = []
        for i in vals:
            if i is None:
                ya.append(None)
            else:
                ya.append(TreeNode(i))
        for i in range(len(ya)):
            if ya[i] is None:
                continue
            if 2*i+1 < len(ya):
                ya[i].left = ya[2*i+1]
            if 2*i+2 < len(ya):
                ya[i].right = ya[2*i+2]
        return ya[0]
    return make_tree_helper(vals)

def print_tree(root):
    # 以树形输出二叉树
    def print_tree_helper(root, depth):
        if root is None:
            return
        print_tree_helper(root.right, depth+1)
        print('    '*depth, root.val)
        print_tree_helper(root.left, depth+1)
    print_tree_helper(root, 0)

# DESIGN
def test_design(ops, args, cls):
    t = cls(*args[0])
    n = len(ops)
    for op,arg in zip(ops[1:], args[1:]):
        res = getattr(t, op)(*arg)
        print(res, end=" ")
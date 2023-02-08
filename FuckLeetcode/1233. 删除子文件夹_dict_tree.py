from typing import List

# “字典树”的结点
class Node:
    def __init__(self, name: str, ref: int=-1) -> None:
        self.name = name
        self.name2snode = dict()
        self.ref = ref


def add_son(root: Node, folders: List[str], ref: int):
    if len(folders) == 0:
        return
    if folders[0] not in root.name2snode:
        son = Node(folders[0])
        if len(folders) == 1:
            # 存在的文件夹的ref idx
            # print(ref)
            son.ref = ref
        root.name2snode[folders[0]] = son
    add_son(root.name2snode[folders[0]], folders[1:], ref)

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        # 有趣的问题，判题的global scope里面有个root，
        # 刚好也是树
        root = Node('/')
        folder.sort()
        
        folders = [f.split('/')[1:] for f in folder]
        # print(folders)
        for i, f in enumerate(folders):
            add_son(root, f, i)

        ans = []
        def dfs(node: Node):
            nonlocal ans
            if node.ref != -1:
                # print(node.ref)
                ans.append(folder[node.ref])
                return
            for c in node.name2snode.values():
                dfs(c)
        dfs(root)
        return ans
s = Solution()
r = s.removeSubfolders(
    # ["/a","/a/b","/c/d","/c/d/e","/c/f"]
    # ["/a","/a/b/c","/a/b/d"]
    ["/a","/a/b/c","/a/b/d"]
)
print(r)
        
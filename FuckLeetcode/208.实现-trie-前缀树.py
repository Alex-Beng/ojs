#
# @lc app=leetcode.cn id=208 lang=python3
#
# [208] 实现 Trie (前缀树)
#

# @lc code=start

class Node:
    def __init__(self, is_end=False):
        self.ise = is_end
        self.children = dict()

class Trie:

    def __init__(self):
        self.head = Node()

    def insert(self, word: str) -> None:

        def ins(node: Node, word: str):
            if word=='':
                node.ise = True
                return
            c = word[0]
            if c not in node.children:
                tnode = Node()
                node.children[c] = tnode
            ins(node.children[c], word[1:])
        ins(self.head, word)

    def search(self, word: str) -> bool:
        def sch(node: Node, word: str) -> bool:
            if word=='':
                return node.ise
            c = word[0]
            if c not in node.children:
                return False
            return sch(node.children[c], word[1:])
        return sch(self.head, word)

    def startsWith(self, prefix: str) -> bool:
        def st_with(node: Node, perf: str) -> bool:
            if perf=='':
                return True
            c = perf[0]
            if c not in node.children:
                return False
            return st_with(node.children[c], perf[1:])
        return st_with(self.head, prefix)

# @lc code=end

ops = ["Trie","insert","search","search","startsWith","insert","search"]
args = [[],["apple"],["apple"],["app"],["app"],["app"],["app"]]
exps = [None, None, True, False, True, None, True]

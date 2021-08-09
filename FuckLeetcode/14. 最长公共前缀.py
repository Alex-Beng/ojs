class trie_node:
    def __init__(self, val):
        self.val = val
        self.sons = dict()
        self.as_end = False
    def have_edge(self, cha):
        if cha in self.sons:
            return True
        else:
            return False

def insert(node:trie_node, string:str):
    if string == "":
        return

    cha = string[0]
    if cha not in node.sons:
        new_node = trie_node(cha)
        node.sons[cha] = new_node
    insert(node.sons[cha], string[1:])

class Solution:
    def longestCommonPrefix(self, strs) -> str:
        root = trie_node(None)
        min_len = float('inf')
        for s in strs:
            min_len = min(min_len, len(s))
            insert(root, s)
        
        ans = ""
        t_ptr = root
        while len(t_ptr.sons.keys()) == 1:
            edges = list(t_ptr.sons.keys())
            ans += edges[0]
            t_ptr = t_ptr.sons[edges[0]]
        return ans[:min_len]
s = Solution()
print(s.longestCommonPrefix(
    # ["flower","flow","flight"]
    # ["dog","racecar","car"]
    ["a", "ac"]

))
                
        
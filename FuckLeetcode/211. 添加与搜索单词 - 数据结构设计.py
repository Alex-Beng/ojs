class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = [None, dict(), False] # val, sons, end-able

    def addWord(self, word: str) -> None:
        def add_wd(node, wd):
            if len(wd) == 0:
                node[2] = True
                return
            
            if wd[0] in node[1]:
                add_wd(node[1][wd[0]], wd[1:])
            else:
                new_node = [wd[0], dict(), False]
                node[1][wd[0]] = new_node
                add_wd(new_node, wd[1:])
        add_wd(self.root, word)

    def search(self, word: str) -> bool:

        def search_wd(node, wd):
            # print(node, wd)
            if len(wd) == 1:
                if wd == '.':
                    for k in node[1].keys():
                        if node[1][k][2]:
                            return True
                    return False
                if wd in node[1].keys() and node[1][wd][2]:
                    return True
                else:
                    return False
            
            cha = wd[0]
            if cha in node[1]:
                # print(node[1][cha], wd[1:])
                return search_wd(node[1][cha], wd[1:])
            elif cha == '.':
                for k in node[1].keys():
                    # print(wd, k, node[1][k])
                    # print(node[1][k], wd[1:])
                    if search_wd(node[1][k], wd[1:]):
                        return True
                return False
            else:
                return False
        return search_wd(self.root, word)

ops = ["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]
args = [[],["at"],["and"],["an"],["add"],["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]
exps = [None,None,None,None,None,False,False,None,True,True,False,False,True,False]

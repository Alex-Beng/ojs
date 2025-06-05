from collections import defaultdict
class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        # 并查集
        parent = {chr(i):chr(i) for i in range(ord('a'), ord('z')+1)}
        
        def find(x, p):
            if p[x] != x:
                p[x] = find(p[x], p)
            return p[x]
        
        def union(x, y, p):
            rootX = find(x, p)
            rootY = find(y, p)
            if rootX != rootY:
                # 将较小的字符作为根节点
                if rootX < rootY:
                    p[rootY] = rootX
                else:
                    p[rootX] = rootY
        

        N = len(s1)
        for i in range(N):
            c1 = s1[i]
            c2 = s2[i]
            union(c1, c2, parent)
        
        res = []
        for c in baseStr:
            res.append(find(c, parent))
        return "".join(res)

INPUT = [
    ("parker", "morris", "parser")
]
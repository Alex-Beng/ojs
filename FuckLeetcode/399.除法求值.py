from queue import Queue

class Solution:
    def calcEquation(self, equations: [[str]], values: [float], queries: [[str]]) -> [float]:
        nodes = set()
        aj_mat = dict()
        n = len(values)
        for i in range(n):
            f, t = equations[i]
            ans = values[i]
            
            if f not in aj_mat:
                aj_mat[f] = dict()
            if t not in aj_mat:
                aj_mat[t] = dict()

            aj_mat[f][t] = ans
            aj_mat[t][f] = 1/ans
            nodes.add(f)
            nodes.add(t)
        ans = []
        for f,t in queries:
            if f not in nodes or t not in nodes:
                ans.append(-1.0)
                continue
            que = Queue()
            que.put((f, 1))
            been = set()
            valid = False
            while not que.empty():
                nd,tans = que.get()
                been.add(nd)
                if nd == t:
                    valid = True
                    ans.append(tans)
                    break
                for to in aj_mat[nd]:
                    if to not in been:
                        que.put((to, tans*aj_mat[nd][to]))
            if not valid:
                ans.append(-1.0)        
        return ans
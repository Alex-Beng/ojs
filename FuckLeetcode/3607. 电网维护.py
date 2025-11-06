from sortedcontainers import SortedList

class Solution:
    def processQueries(self, c: int, connections: 'List[List[int]]', queries: 'List[List[int]]') -> 'List[int]':
        i2head = {}
        ajList = {}
        for i, j in connections:
            ajList.setdefault(i, []).append(j)
            ajList.setdefault(j, []).append(i)
        # print(ajList)
        def bfs(i):
            ret = SortedList()
            qrq = [i]
            while qrq:
                # print(qrq)
                _i = qrq.pop(0)
                i2head[_i] = i
                ret.add(_i)
                for _j in ajList.get(_i, []):
                    if _j not in i2head:
                        i2head[_j] = i
                        qrq.append(_j)
            return ret
        
        allList: 'dict[int, SortedList]' = {}
        for i in range(1, c+1):
            if i not in i2head:
                # print(i, bfs(i))
                allList[i] = bfs(i)
        # print(i2head, allList)
        downs = set()
        ans = []
        for op, i in queries:
            # print(op, i, allList, downs, ans)
            if op == 1:
                if i not in downs:
                    ans.append(i)
                else:
                    sList = allList[i2head[i]]
                    if not sList:
                        ans.append(-1)
                    else:
                        ans.append(sList[0])
            elif op == 2:
                downs.add(i)
                sList = allList[i2head[i]]
                sList.discard(i)
        return ans
INPUT = [
    # (5, [[1,2],[2,3],[3,4],[4,5]], [[1,3],[2,1],[1,1],[2,2],[1,2]])
    # (2, [[2,1]], [[1,1],[1,2],[2,2],[2,1],[2,2],[2,2],[2,1],[1,1],[2,2],[2,1],[1,1],[2,1],[2,2],[1,1],[1,2],[1,1],[1,1],[2,1],[1,1],[2,2],[2,2],[2,1],[1,2],[2,2],[1,1],[2,1],[2,2],[2,2],[1,1],[2,2]])
    (3, [[2,3],[1,2],[1,3]], [[1,1],[1,2],[1,2],[1,3],[1,3],[1,1],[2,3],[1,1],[2,2],[2,2],[1,2],[1,3],[2,1],[2,1],[1,3],[2,1],[2,3],[1,3],[1,3],[2,2],[1,1],[2,2],[1,2],[1,1],[1,2],[1,3],[1,2],[1,3],[2,2],[2,2],[2,3],[1,3],[1,2],[2,3],[1,2],[2,3],[2,3],[2,2],[2,2],[1,1],[2,3],[1,1]])
]
                

        
from functools import lru_cache

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: [str]) -> int:
        wordList.append(beginWord)
        wordList = list(set(wordList))
        
        s_len = len(beginWord)
        n = len(wordList)

        wd_ids = [i for i in range(n)]
        wd2id = dict(zip(wordList, wd_ids))

        if not endWord in wordList:
            return 0
        
        aj_mat = [[0]*n for _ in range(n)]
        # 判断图中节点的连通性
        for i, wd in enumerate(wordList):
            wd = list(wd)
            for j in range(s_len):
                old_c = wd[j]
                for c in range(97, 123):
                    c = chr(c)
                    if c == old_c:
                        continue
                    wd[j] = c
                    new_s = ''.join(wd)
                    if new_s in wd2id:
                        aj_mat[i][wd2id[new_s]] = 1
                    wd[j] = old_c

        
        # BFS
        b_idx = wordList.index(beginWord)
        que = [b_idx]
        been = [0]*n
        been[b_idx] = 1
        while len(que) != 0:
            # print(been)
            curr = que[0]
            del que[0]

            if wordList[curr] == endWord:
                break

            for i in range(n):
                if aj_mat[curr][i] and not been[i]:
                    been[i] = been[curr] + 1
                    que.append(i)
        e_idx = wordList.index(endWord)
        return been[e_idx]
s = Solution()
r = s.ladderLength(
'hit', 'cog', ["hot","dot","dog","lot","log","cog"]
)
print(r)
from typing import List, Optional
from copy import deepcopy

class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        n = len(wordList)
        slen = len(wordList[0])

        wordList = set(wordList)
        if endWord not in wordList:
            return []

        wd2dist = dict()
        wd2dist[beginWord] = 0

        def ff():
            curr = beginWord
            que = [curr]
            while len(que):
                node = que[0]
                del que[0]
                curr_wd = node

                for i in range(slen):
                    for j in range(ord('a'), ord('z')+1):
                        new_wd = curr_wd[:i] + chr(j) + curr_wd[i+1:]
                        if new_wd in wordList and new_wd not in wd2dist:
                            wd2dist[new_wd] = wd2dist[curr_wd] + 1
                            if new_wd == endWord:
                                return
                            que.append(new_wd)
                
        ff()

        ans = []
        t_path = [endWord]
        def dfs(node):
            curr = node
            if curr == beginWord:
                ans.append(t_path[::-1])
            que = [curr]
            while len(que):
                node = que[0]
                del que[0]
                curr_wd = node

                for i in range(slen):
                    for j in range(ord('a'), ord('z')+1):
                        new_wd = curr_wd[:i] + chr(j) + curr_wd[i+1:]
                        if new_wd in wd2dist and wd2dist[new_wd]+1 == wd2dist[curr_wd]:
                            t_path.append(new_wd)
                            dfs(new_wd)
                            t_path.pop()
        dfs(endWord)

        return ans        



s = Solution()
r = s.findLadders(
    # "hit", "cog", ["hot","dot","dog","lot","log","cog"]
    # "hit", "cog", ["hot","dot","dog","lot","log"]
    # "hot", "dog", ["hot","dog"]
    "red", "tax", ["ted","tex","red","tax","tad","den","rex","pee"]
)
print(r)
# [["red","ted","tad","tax"],
#  ["red","ted","tex","tax"],
#  ["red","rex","tex","tax"]]
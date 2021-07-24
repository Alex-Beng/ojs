class Solution:
    def restoreArray(self, adjacentPairs):
        hash_map = dict()
        for idx,pair in enumerate(adjacentPairs):
            for n in pair:
                if n in hash_map:
                    hash_map[n].append(idx)
                else:
                    hash_map[n] = [idx]
        t_num, t_n2idx = None, None
        for key in hash_map:
            if len(hash_map[key]) == 1:
                t_num = key
                t_n2idx = hash_map[key]
                break
        ans = [t_num]
        while True:
            adjacentPairs[t_n2idx[0]].remove(t_num)
            next_num = adjacentPairs[t_n2idx[0]][0]

            ans.append(next_num)
            # print(next_num, t_n2idx, hash_map[next_num])
            hash_map[next_num].remove(t_n2idx[0])
            # print(hash_map[next_num])
            if hash_map[next_num] == []:
                break
            else:
                t_num = next_num
                t_n2idx = hash_map[next_num]
        return ans
            
s = Solution()
print(s.restoreArray( [[100000,-100000]]))
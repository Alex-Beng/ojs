class Solution:
    def partitionLabels(self, s: str) -> [int]:
        cha2section = dict()
        for idx,cha in enumerate(s):
            if cha in cha2section:
                cha2section[cha][1] = idx
            else:
                cha2section[cha] = [idx, idx]
        sections = list(cha2section.values())
        sections.sort(key=lambda k: k[0])

        ans = [sections[0]]
        for i in range(1, len(sections)):
            sec = sections[i]
            if sec[0] < ans[-1][1]:
                # merge 
                ans[-1][1] = max(ans[-1][1], sec[1])
            else:
                # new 
                ans.append(sec)
        
        return [i[1]-i[0]+1 for i in ans]
s = Solution()
print(s.partitionLabels(
    "ababcbacadefegdehijhklij"
))
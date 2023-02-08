from typing import List


class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        # 子文件夹必比父亲路径长
        folder.sort()
        n = len(folder)
        ans = [folder[0]]
        sl_idx = 0
        ft_idx = 1
        while ft_idx < n and sl_idx <= ft_idx:
            sl_name = folder[sl_idx]
            ft_name = folder[ft_idx]
            slen = len(sl_name)
            # 如果ft不是sl的子文件夹
            if sl_name != ft_name[:slen] or ft_name[slen]!='/':
                sl_idx = ft_idx
                ans.append(ft_name)
            ft_idx += 1
            
        return ans
s = Solution()
r = s.removeSubfolders(
    ["/a","/a/b","/c/d","/c/d/e","/c/f"]
    # ["/a/b/c","/a/b/ca","/a/b/d"]
)
print(r)
        
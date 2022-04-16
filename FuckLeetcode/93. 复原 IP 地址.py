class Solution:
    def restoreIpAddresses(self, s: str) -> [str]:
        def ip_valid(ip):
            ip = [int(t) for t in ip]
            if len(ip)!=4 or min(ip)<0 or max(ip)>255:
                return False
            else:
                return True
        n = len(s)
        t_ans = []
        ans = []
        def dfs(layer: int, begin: int):
            nonlocal t_ans, n
            if layer==4 or begin>=n:
                # print(t_ans)
                if ip_valid(t_ans):
                    ans.append('.'.join(t_ans))
                return
            if s[begin]=='0':
                if layer==3 and begin+1 != n:
                    return
                t_ans += ['0']
                dfs(layer+1, begin+1)
                del t_ans[-1]
                return
            
            if layer<3:
                for tlen in range(1, 4):
                    t_ans += [s[begin:begin+tlen]]
                    dfs(layer+1, begin+tlen)
                    del t_ans[-1]
            else:
                t_ans += [s[begin:]]
                dfs(layer+1, begin+1)
                del t_ans[-1]
        dfs(0, 0)
        print(ans)
        return ans
s = Solution()
s.restoreIpAddresses(
    # "25525511135",
    # "101023"
    # "0000"
    "101023"
    )
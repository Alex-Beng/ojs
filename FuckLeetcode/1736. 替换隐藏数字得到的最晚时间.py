from copy import deepcopy
class Solution:
    def maximumTime(self, time: str) -> str:
        time = ''.join(time.split(":"))
        time = list(time)
        ans = deepcopy(time)
        for idx,tb in enumerate(time):
            if tb == '?':
                if idx == 0:
                    if time[idx+1] in ['?']+[str(i) for i in range(4)]:
                        ans[idx] = '2'
                    else:
                        ans[idx] = '1'
                elif idx == 1:
                    if time[idx-1] in ['?', '2']:
                        ans[idx] = '3'
                    else:
                        ans[idx] = '9'
                elif idx == 2:
                    ans[idx] = '5'
                else:
                    ans[idx] = '9'
        ans.insert(2, ':')
        return ''.join(ans)
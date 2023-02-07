from typing import List

class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        n = len(keyName)

        name2tims = dict()
        for i in range(n):
            name = keyName[i]
            time = keyTime[i]
            name2tims.setdefault(name, []).append(time)
        # print(name2tims)
        ans = []
        def in_an_hour(pp_t, t) -> bool:
            H, M = map(int, t.split(':'))
            h, m = map(int, pp_t.split(':'))
            diff_min = -1
            if H < h:
                # 过一天了
                # 其实无需判断，题面给了“某一天”
                return False
            # 无需判断所有四种情况
            '''
            if M >= m:
                # if H >= h:
                diff_min = (H-h)*60 + M-m
            else:
                diff_min = (H-1-h)*60 + M+60-m
            '''
            # 甚至无需判断余下的两种情况
            diff_min = (H-h)*60 + M-m
            return diff_min <= 60

        def check(name2tims, ans):
            for name, times in name2tims.items():
                # print(name)
                # need to sort times
                times = sorted(times)
                # print(times)
                for i, t in enumerate(times[2:]):
                    pp_t = times[i]
                    if in_an_hour(pp_t, t):
                        ans.append(name)
                        break
        check(name2tims, ans)

        return sorted(ans)


keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"]
keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
keyName = ["alice","alice","alice","bob","bob","bob","bob"]
keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
keyName = ["john","john","john"];keyTime = ["23:58","23:59","00:01"]
keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"];keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
keyName = ["a","a","a","a","a","b","b","b","b","b","b"];keyTime = ["04:48","23:53","06:36","07:45","12:16","00:52","10:59","17:16","00:36","01:26","22:42"]

s = Solution()
r = s.alertNames(keyName, keyTime)
print(r)
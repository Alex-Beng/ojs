class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        ans = 0
        if ruleKey == 'type':
            for item in items:
                if item[0] == ruleValue:
                    ans += 1
    
        elif ruleKey == 'color':
            for item in items:
                if item[1] == ruleValue:
                    ans += 1

        else:
            for item in items:
                if item[2] == ruleValue:
                    ans += 1
        return ans

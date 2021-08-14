class Solution:
    def unhappyFriends(self, n: int, preferences: [[int]], pairs: [[int]]) -> int:
        pp_pp2score = [dict() for i in range(n)]
        pp_score2pp = [dict() for i in range(n)]
        pp2pair = dict()

        for pp in range(n):
            perfer = preferences[pp]
            for i in range(n-1):
                score = n-i
                pp_pp2score[pp][perfer[i]] = score
                pp_score2pp[pp][score] = perfer[i]
        for pair in pairs:
            pp2pair[pair[0]] = pair[1]
            pp2pair[pair[1]] = pair[0]

        ans = 0
        for pp in range(n):
            pp_pair = pp2pair[pp]
            t_score = pp_pp2score[pp][pp_pair]
            if t_score == n:
                pass
            else:
                for score in range(t_score+1, n+1):
                    pp_s_pair = pp_score2pp[pp][score]
                    pp_s_pair_pair = pp2pair[pp_s_pair]
                    
                    pp_s_pair_2_pp_s_pair_pair_score = pp_pp2score[pp_s_pair][pp_s_pair_pair]
                    pp_s_pair_2_pp_score = pp_pp2score[pp_s_pair][pp]
                    if pp_s_pair_2_pp_s_pair_pair_score < pp_s_pair_2_pp_score:
                        ans += 1
                        break
        return ans
s = Solution()
print(s.unhappyFriends(
    # 4,  [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]], [[1, 3], [0, 2]]
    # 2, [[1], [0]], [[1, 0]]
    4, [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], [[0, 1], [2, 3]]
)
)
                
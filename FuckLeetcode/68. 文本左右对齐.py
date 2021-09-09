class Solution:
    def fullJustify(self, words: [str], maxWidth: int) -> [str]:
        n = len(words)
        
        line_lens = [len(words[0])]
        lines = [[words[0]]]
        for i in range(1, n):
            wd = words[i]
            wd_len = len(wd)
            if wd_len+1+line_lens[-1] <= maxWidth:
                # add curr line
                lines[-1].append(wd)
                line_lens[-1] += (wd_len+1)
            else:
                lines.append([wd])
                line_lens.append(wd_len)
        line_nums = len(line_lens)
        ans = []
        for i in range(line_nums-1):
            line = lines[i]
            line_len = line_lens[i]

            word_num = len(line)
            space_num = maxWidth-line_len
            gap_num = word_num-1

            if gap_num == 0:
                ans.append(line[0]+' '*space_num)
                continue

            avg_num = space_num//gap_num 
            extra_num = space_num%gap_num 

            t_ans = line[0]
            for j in range(extra_num):
                t_ans += ' '*(1+avg_num+1)
                t_ans += line[j+1]

            for j in range(extra_num+1, word_num):
                t_ans += ' '*(1+avg_num)
                t_ans += line[j]
            ans.append(t_ans)
        # 最后一行左对齐
        t_ans = ' '.join(lines[-1])
        t_ans += ' '*(maxWidth-line_lens[-1])
        ans.append(t_ans)

        return ans

s = Solution()
res = s.fullJustify(
#  ["This", "is", "an", "example", "of", "text", "justification."], 16
#   ["What","must","be","acknowledgment","shall","be"], 16
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], 20
)
for r in res:
    print(r, 'cao')
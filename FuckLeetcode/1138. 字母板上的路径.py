class Solution:
    def __init__(self) -> None:
        self.ch2pos = {'a': (0, 0), 'b': (0, 1), 'c': (0, 2), 'd': (0, 3), 'e': (0, 4), 'f': (1, 0), 'g': (1, 1), 'h': (1, 2), 'i': (1, 3), 'j': (1, 4), 'k': (2, 0), 'l': (2, 1), 'm': (2, 2), 'n': (2, 3), 'o': (2, 4), 'p': (3, 0), 'q': (3, 1), 'r': (3, 2), 's': (3, 3), 't': (3, 4), 'u': (4, 0), 'v': (4, 1), 'w': (4, 2), 'x': (4, 3), 'y': (4, 4), 'z': (5, 0)}
        self.pos2ch = {(0, 0): 'a', (0, 1): 'b', (0, 2): 'c', (0, 3): 'd', (0, 4): 'e', (1, 0): 'f', (1, 1): 'g', (1, 2): 'h', (1, 3): 'i', (1, 4): 'j', (2, 0): 'k', (2, 1): 'l', (2, 2): 'm', (2, 3): 'n', (2, 4): 'o', (3, 0): 'p', (3, 1): 'q', (3, 2): 'r', (3, 3): 's', (3, 4): 't', (4, 0): 'u', (4, 1): 'v', (4, 2): 'w', (4, 3): 'x', (4, 4): 'y', (5, 0): 'z'}
    def alphabetBoardPath(self, target: str) -> str:
        ch2pos = self.ch2pos
        pos2ch = self.pos2ch
        ans = ''
        curr_pos = (0,0)
        for c in target:
            if c == pos2ch[curr_pos]:
                ans += '!'
            else:
                to_pos = ch2pos[c]
                dr, dc = to_pos[0]-curr_pos[0], to_pos[1]-curr_pos[1]
                if dr >= 0:
                    dirc = ''
                    if dc < 0:
                        dirc = 'L'
                    elif dc > 0:
                        dirc = 'R'
                    ans += dirc*abs(dc)
                    dirc = ''
                    if dr != 0:
                        dirc = 'D'
                    ans += dirc*dr
                else:
                    dirc = ''
                    if dr != 0:
                        dirc = 'U'
                    ans += dirc*abs(dr)
                    dirc = ''
                    if dc < 0:
                        dirc = 'L'
                    elif dc > 0:
                        dirc = 'R'
                    ans += dirc*abs(dc)
                ans += '!'
                curr_pos = to_pos
        return ans
ch2pos = dict()
pos2ch = dict()
for c in range(26):
    ch = chr(ord('a')+c)
    row = c // 5
    col = c % 5
    ch2pos[ch] = (row, col)
    pos2ch[(row, col)] = ch
print(pos2ch)
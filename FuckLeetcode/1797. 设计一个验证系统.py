from util import test_design

class AuthenticationManager:

    def __init__(self, timeToLive: int):
        self.ttl = timeToLive

        # token-st_time pair
        # a SoA versus LL problem !
        # ops\complex | LL | SoA
        # generate | O(1) | O(1)
        # renew | O(1) | O(log(n))(?)
        # cnt | O(n) | O(log(n))
        # update | O(n) | O(log(n))
        # Struct of Array may better?
        self.tokens = []
        self.st_times = []

        self.tk2stt = dict()

    def update(self, currentTime: int) -> None:
        # print(self.tokens, currentTime)
        valid_idx = 0
        n = len(self.tokens)
        currentTime -= self.ttl
        while valid_idx < n and self.st_times[valid_idx] <= currentTime:
            valid_idx += 1

        invalid_tk = self.tokens[:valid_idx] 
        # delete !
        for tk in invalid_tk:
            del self.tk2stt[tk]
        self.tokens = self.tokens[valid_idx:]
        self.st_times = self.st_times[valid_idx:]
        # print(self.tokens, currentTime+self.ttl)

    def generate(self, tokenId: str, currentTime: int) -> None:
        self.update(currentTime)
        
        self.tokens.append(tokenId)
        self.st_times.append(currentTime)
        self.tk2stt[tokenId] = currentTime

    def renew(self, tokenId: str, currentTime: int) -> None:
        self.update(currentTime)
        if tokenId in self.tk2stt:
            # 如果还有效
            idx = self.tokens.index(tokenId)
            del self.tokens[idx]
            del self.st_times[idx]
            self.generate(tokenId, currentTime)

            
    def countUnexpiredTokens(self, currentTime: int) -> int:
        self.update(currentTime)
        # print(self.tokens)
        return len(self.tokens)


ops = ["AuthenticationManager", "renew", "generate", "countUnexpiredTokens", "generate", "renew", "renew", "countUnexpiredTokens"]
args = [[5], ["aaa", 1], ["aaa", 2], [6], ["bbb", 7], ["aaa", 8], ["bbb", 10], [15]]
test_design(ops, args, AuthenticationManager)
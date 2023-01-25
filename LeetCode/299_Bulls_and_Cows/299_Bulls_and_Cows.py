from typing import *

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1

        cache1 = {}
        for c in secret:
            cache1[c] = cache1.get(c, 0) + 1

        cache2 = {}
        for c in guess:
            cache2[c] = cache2.get(c, 0) + 1

        cows = 0
        for k, v in cache1.items():
            cows += min(v, cache2.get(k, 0))

        return f"{bulls}A{cows-bulls}B"
        

s = Solution()

print(s.getHint("1807", "7810"))
print(s.getHint("1123", "0111"))

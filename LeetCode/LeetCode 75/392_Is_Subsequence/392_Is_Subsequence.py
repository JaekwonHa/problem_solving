from typing import *

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) > len(t):
            return False
        if len(s) == 0:
            return True
        
        i = 0
        for x in t:
            if s[i] == x:
                i += 1
            if i == len(s):
                return True
        return True if i == len(s) else False
        

s = Solution()

print(s.isSubsequence("abc", "ahdgbc"))
print(s.isSubsequence("axc", "ahdgbc"))
print(s.isSubsequence("", "ahdgbc"))

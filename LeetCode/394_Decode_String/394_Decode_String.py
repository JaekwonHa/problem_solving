from typing import *

class Solution:
    digits = "0123456789"

    def recursiveDecode(self, k: int, s: str) -> str:

    def decodeString(self, s: str) -> str:
        stack = []
        for c in s:
            if c in self.digits:
                stack.extend(self.recursiveDecode(int(c), ))
        

s = Solution()

print()

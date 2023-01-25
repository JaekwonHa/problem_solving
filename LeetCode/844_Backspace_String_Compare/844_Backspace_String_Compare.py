from typing import *

class Solution:
    # def backspaceCompare(self, s: str, t: str) -> bool:
    #     stack_s = []
    #     stack_t = []

    #     for c in s:
    #         if c == '#':
    #             if len(stack_s)>0:
    #                 stack_s.pop()
    #         else:
    #             stack_s.append(c)
    #     for c in t:
    #         if c == '#':
    #             if len(stack_t)>0:
    #                 stack_t.pop()
    #         else:
    #             stack_t.append(c)

    #     return stack_s == stack_t
    
    def processBackspace(self, s: str, i: int) -> int:
        count = 0
        while i >= 0:
            if s[i] == '#':
                count += 1
                i -= 1
            elif count > 0:
                count -= 1
                i -= 1
            else:
                break
        return i
    
    def backspaceCompare(self, s: str, t: str) -> bool:
        i, j = len(s)-1, len(t)-1

        while i>=0 or j>=0:
            i = self.processBackspace(s, i)
            j = self.processBackspace(t, j)

            if i < 0 and j < 0:
                break
            if i < 0 and j >= 0:
                return False
            if i >= 0 and j < 0:
                return False
            if s[i] != t[j]:
                return False
            i -= 1
            j -= 1
        return True


s = Solution()

print(s.backspaceCompare("ab#c", "ad#c"))
print(s.backspaceCompare("ab##", "c#d#"))
print(s.backspaceCompare("a#c", "b"))
print(s.backspaceCompare("###", "#"))

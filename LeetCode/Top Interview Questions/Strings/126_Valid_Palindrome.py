import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub(r'[\W_]', '', s.lower())
        return s == s[::-1]


solution = Solution()
print(solution.isPalindrome("ab_a"))

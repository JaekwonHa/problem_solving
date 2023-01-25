from typing import *

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        first = strs[0]
        result = []

        for i, c in enumerate(first):
            for str in strs:
                if len(str) <= i or str[i] != c:
                    return ''.join(result)
            result.append(c)
        return ''.join(result)


s = Solution()

input = ["flower","flow","flight"]
print(s.longestCommonPrefix(input))

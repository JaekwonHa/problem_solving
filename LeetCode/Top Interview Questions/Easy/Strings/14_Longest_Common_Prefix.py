from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        minimum = len(min(strs, key=lambda s: len(s)))
        for i in range(minimum):
            prefix = strs[0][i]
            for s in strs:
                if prefix != s[i]:
                    return strs[0][0:i]
            if i + 1 == minimum:
                return strs[0][0:minimum]
        return ""


solution = Solution()
print(solution.longestCommonPrefix(["flower","flow","flight"]))

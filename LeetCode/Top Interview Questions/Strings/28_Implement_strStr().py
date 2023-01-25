class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        for i in range(0, len(haystack) - len(needle) + 1):
            if haystack[i] != needle[0]:
                continue
            find = True
            for j in range(0, len(needle)):
                if haystack[i + j] != needle[j]:
                    find = False
                    break
            if find:
                return i
        return -1

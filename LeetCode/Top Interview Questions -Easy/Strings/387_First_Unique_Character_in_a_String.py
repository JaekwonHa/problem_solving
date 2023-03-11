class Solution:
    def firstUniqChar(self, s: str) -> int:
        hash = {s[i]: i for i in range(0, len(s))}
        for i in range(0, len(s)):
            if hash.get(s[i]) is not None and hash.get(s[i]) == i:
                return i
            if hash.get(s[i]) is not None:
                del hash[s[i]]
        return -1


solution = Solution()
print(solution.firstUniqChar("cc"))


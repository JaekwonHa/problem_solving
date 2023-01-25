from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        l = len(s) - 1
        for x in range(0, int(len(s)/2)):
            s[x] = chr(ord(s[x]) ^ ord(s[l-x]))
            s[l-x] = chr(ord(s[x]) ^ ord(s[l-x]))
            s[x] = chr(ord(s[x]) ^ ord(s[l-x]))


solution = Solution()
print(solution.reverseString(["h","e","l","l","o"]))

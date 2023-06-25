from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash = defaultdict(list)

        for str in strs:
            s = ''.join(sorted(str))
            hash[s].append(str)

        answer = []
        for key, value in hash.items():
            answer.append(value)

        return answer

s = Solution()

strs = ["eat","tea","tan","ate","nat","bat"]
print(s.groupAnagrams(strs))

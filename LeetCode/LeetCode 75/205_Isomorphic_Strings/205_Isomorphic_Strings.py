from typing import *

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # hash_map_s = {}
        # hash_map_t = {}
        # for x, y in zip(s,t):
        #     if (hash_map_s.get(x) != None and hash_map_s.get(x) != y)\
        #         or (hash_map_t.get(y) != None and hash_map_t.get(y) != x):
        #         return False
        #     hash_map_s[x] = y
        #     hash_map_t[y] = x
        # return True
        
        if len(set(s)) != len(set(t)):
            return False
        hash_map = {}
        for i in range(len(s)):
            if t[i] not in hash_map:
                hash_map[t[i]] = s[i]
            elif hash_map.get(t[i]) != s[i]:
                return False
        return True


s = Solution()
print(s.isIsomorphic("foo", "bar"))
print(s.isIsomorphic("badc", "baba"))
print(s.isIsomorphic("paper", "title"))

from typing import List

class Solution:

    def isAnagram(self, s: dict, p: dict) -> bool:
        for key, value in s.items():
            if value == 0:
                continue
            if key in p.keys() and p[key] == value:
                continue
            return False
        return True

    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []

        hash_s, hash_p = {}, {}

        for i in range(len(p)):
            hash_p.setdefault(p[i], 0)
            hash_p[p[i]] += 1
        
        for i in range(len(p)):
            hash_s.setdefault(s[i], 0)
            hash_s[s[i]] += 1

        answer = []

        if self.isAnagram(hash_s, hash_p):
            answer.append(0)

        tail, head = 0, len(p)

        for i in range(head, len(s)):
            hash_s[s[tail]] -= 1
            if hash_s[s[tail]] == 0:
                del(hash_s[s[tail]])
            hash_s.setdefault(s[head], 0)
            hash_s[s[head]] += 1
            tail += 1
            head += 1
            # if self.isAnagram(hash_s, hash_p):
            #     answer.append(tail)
            if hash_s == hash_p:
                answer.append(tail)

        return answer

s = Solution()

answer = s.findAnagrams("cbaebabacd", "abc")
print(answer)
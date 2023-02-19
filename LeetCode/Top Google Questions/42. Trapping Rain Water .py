from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        s = []
        answer = 0
        for i in range(0, len(height)):
            if height[i] == 0:
                continue
            if len(s) == 0:
                s.append(i)
                continue
            if height[s[0]] >= height[i]:
                s.append(i)
                continue
            answer += (i - s[0]) * height[s[0]]
            s = [i]

        while 0 < len(s):
            last = s.pop()
            if len(s) == 0:
                answer += height[last]
                continue
            while 0 < len(s) and height[s[-1]] < height[last]:
                s.pop()
            answer += (last - s[-1]) * height[last]

        return answer - sum(height)


s = Solution()
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(s.trap(height))

height = [4,2,0,3,2,5]
print(s.trap(height))

height = [2,0,2]
print(s.trap(height))

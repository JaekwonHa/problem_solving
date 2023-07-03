from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        stack = []
        max_height = 0
        answer = 0

        for i in range(len(height)):
            if len(stack) == 0:
                stack.append(height[i])
                max_height = height[i]
                continue

            if max_height > height[i]:
                stack.append(height[i])
                continue

            if max_height <= height[i]:
                while len(stack) != 0:
                    answer += (max_height - stack[-1])
                    stack.pop()
                max_height = height[i]
                stack.append(height[i])

        height = stack[::-1]
        stack = []
        for i in range(len(height)):
            if len(stack) == 0:
                stack.append(height[i])
                max_height = height[i]
                continue

            if max_height > height[i]:
                stack.append(height[i])
                continue

            if max_height <= height[i]:
                while len(stack) != 0:
                    answer += (max_height - stack[-1])
                    stack.pop()
                max_height = height[i]
                stack.append(height[i])

        return answer


s = Solution()

height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(s.trap(height))

from typing import List
from collections import defaultdict

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        hash_two = defaultdict(list)

        nums.sort()
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                hash_two[nums[i] + nums[j]].append([i, j])

        answer = set()
        for i in range(len(nums)):
            key = -nums[i]
            if key in hash_two.keys():
                for j in range(len(hash_two[key])):
                    temp = sorted([i, *hash_two[key][j]])
                    answer.add((temp[0], temp[1], temp[2]))

        answer2 = []
        for i in answer:
            answer2.append([nums[i[0]], nums[i[1]], nums[i[2]]])

        return answer2

s = Solution()

nums = [-1,0,1,2,-1,-4]
print(s.threeSum(nums))

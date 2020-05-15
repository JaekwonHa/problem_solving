class Solution:
    def rotate_level2(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(k):
            num = nums.pop()
            nums.insert(0, num)

    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if k > len(nums):
            k = k - len(nums)
        nums.reverse()
        nums[:k] = nums[:k][::-1]
        nums[k:] = nums[k:][::-1]

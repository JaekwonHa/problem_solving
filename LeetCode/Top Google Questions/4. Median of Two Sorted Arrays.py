import sys
from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        total = len(nums1) + len(nums2)
        half = (len(nums1) + len(nums2)) // 2

        if len(nums1) == 0 or len(nums2) == 0:
            temp = nums1 + nums2
            if len(temp) % 2 == 0:
                return (temp[half-1] + temp[half]) / 2
            else:
                return temp[half]

        if nums1[-1] <= nums2[0]:
            temp = nums1 + nums2
            if len(temp) % 2 == 0:
                return (temp[half-1] + temp[half]) / 2
            else:
                return temp[half]
        if nums1[0] >= nums2[-1]:
            temp = nums2 + nums1
            if len(temp) % 2 == 0:
                return (temp[half-1] + temp[half]) / 2
            else:
                return temp[half]

        left, right = 0, len(nums1)-1
        while left <= right:
            mid1 = (left + right) // 2
            mid2 = half - (mid1+1) - 1

            Aleft = nums1[mid1] if mid1 >= 0 else -sys.maxsize
            Aright = nums1[mid1+1] if mid1+1 < len(nums1) else sys.maxsize
            Bleft = nums2[mid2] if mid2 >= 0 else -sys.maxsize
            Bright = nums2[mid2+1] if mid2+1 < len(nums2) else sys.maxsize

            if Aleft <= Bright and Bleft <= Aright:
                if total % 2 == 0:
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
                else:
                    return min(Aright, Bright)

            if Aleft <= Bright:
                left = mid1 + 1
            else:
                right = mid1 - 1

        # while True로 놓고 아래 코드는 제거해도 된다
        mid1 = (right) // 2
        mid2 = half - (mid1 + 1) - 1

        Aleft = nums1[mid1] if mid1 >= 0 else -sys.maxsize
        Aright = nums1[mid1 + 1] if mid1 + 1 < len(nums1) else sys.maxsize
        Bleft = nums2[mid2] if mid2 >= 0 else -sys.maxsize
        Bright = nums2[mid2 + 1] if mid2 + 1 < len(nums2) else sys.maxsize

        if Aleft <= Bright and Bleft <= Aright:
            if total % 2 == 0:
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
            else:
                return min(Aright, Bright)


s = Solution()
nums1 = [1,3]
nums2 = [2]
print(s.findMedianSortedArrays(nums1, nums2))

nums1 = [1,2]
nums2 = [3,4]
print(s.findMedianSortedArrays(nums1, nums2))

nums1 = [3,4]
nums2 = [1,2]
print(s.findMedianSortedArrays(nums1, nums2))

nums1 = [1,2,3,4,5]
nums2 = [1,2,3,4,5,6,7]
print(s.findMedianSortedArrays(nums1, nums2))

nums1 = [0,0,0,0,0]
nums2 = [-1,0,0,0,0,0,1]
print(s.findMedianSortedArrays(nums1, nums2))

nums1 = [3]
nums2 = [-2,-1]
print(s.findMedianSortedArrays(nums1, nums2))

nums1 = [1]
nums2 = [2,3]
print(s.findMedianSortedArrays(nums1, nums2))

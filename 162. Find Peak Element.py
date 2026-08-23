class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            middle = (left + right) // 2
            if nums[middle] < nums[middle + 1]:
                left = middle + 1
            elif nums[middle] < nums[middle - 1]:
                right = middle - 1
            else:
                return middle
        return left

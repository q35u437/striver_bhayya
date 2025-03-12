#
# @lc app=leetcode id=2529 lang=python3
#
# [2529] Maximum Count of Positive Integer and Negative Integer
#

# @lc code=start
class Solution:
    def lastNegative(self, nums):
        left = 0
        right = len(nums)
        while left < right:
            middle = (left + right) // 2
            if nums[middle] < 0:
                left = middle + 1
            else:
                right = middle
        return left

    def firstPositive(self, nums):
        left = 0
        right = len(nums)
        while left < right:
            middle = (left + right) // 2
            if nums[middle] <= 0:
                left = middle + 1
            else:
                right = middle
        return left
    def maximumCount(self, nums: List[int]) -> int:
        return max(len(nums) - self.firstPositive(nums), self.lastNegative(nums))
        
# @lc code=end


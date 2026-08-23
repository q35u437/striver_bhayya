class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            middle = (left + right) // 2

            # Make middle even, so it should be the first element of a pair.
            if middle % 2 == 1:
                middle -= 1

            if nums[middle] == nums[middle + 1]:
                left = middle + 2
            else:
                right = middle

        return nums[left]

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        answer = 50001
        while left <= right:
            middle = (left + right) // 2
            if nums[left] <= nums[middle]:
                answer = min(answer, nums[left])
                left = middle + 1
            else:
                answer = min(answer, nums[middle])
                right = middle - 1
        return answer

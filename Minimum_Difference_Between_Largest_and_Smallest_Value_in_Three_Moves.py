class Solution:
    def minDifference(self, nums: List[int]) -> int:
        length = len(nums)
        if length <= 4:
            return 0
        else:
            nums.sort()
            answer = nums[-1]-nums[3]
            answer = min(answer, nums[-4] - nums[0])
            answer = min(answer, nums[-2] - nums[2])
            answer = min(answer, nums[-3] - nums[1])
            return answer

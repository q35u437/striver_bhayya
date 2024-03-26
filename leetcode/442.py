class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        result = []
        length = len(nums)
        for index in range(length):
            if nums[abs(nums[index])-1] < 0:
                result.append(abs(nums[index]))
            else:
                nums[abs(nums[index])-1] = -nums[abs(nums[index])-1]
        return result

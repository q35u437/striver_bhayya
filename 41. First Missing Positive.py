class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        length = len(nums)
        for index in range(length):
            if nums[index] < 0:
                nums[index] = 0
        for index in range(length):
            if abs(nums[index]) >= 1 and abs(nums[index]) <= length:
                if nums[abs(nums[index])-1] > 0:
                    nums[abs(nums[index])-1] *= -1
                elif nums[abs(nums[index])-1] == 0:
                    nums[abs(nums[index])-1] = -length
        for index in range(1,length+1):
            if nums[index-1] >= 0:
                return index
        return length+1

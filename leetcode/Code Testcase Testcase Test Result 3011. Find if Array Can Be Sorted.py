class Solution:
    def countBits(self, num):
        counter = 0
        while num:
            counter += num%2
            num = num // 2
        return counter
    def canSortArray(self, nums: List[int]) -> bool:
        d = {}
        for i in range(0, len(nums)):
            d[i] = self.countBits(nums[i])
        for i in range(0, len(nums)):
            ending = -1
            for j in range(len(nums)-1, i, -1):
                if nums[j] < nums[i]:
                    ending = j
                    break
            if ending != -1:
                if d[i] != d[ending]:
                    return False
                else:
                    for index in range(i+1, ending):
                        if d[index] != d[i]:
                            return False
        return True
            

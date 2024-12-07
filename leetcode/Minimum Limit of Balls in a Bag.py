class Solution:
    def check(self, nums, maxOperations, middle):
        totalOps = 0
        for i in nums:
            totalOps += ceil(i/middle) - 1
        return totalOps <= maxOperations
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        if maxOperations == 0:
            return max(nums)
        left = 1
        right = max(nums)
        answer = -1
        while left <= right:
            middle = (left+right)//2
            if self.check(nums, maxOperations, middle):
                right = middle-1
                answer = middle
            else:
                left = middle+1
        return answer

class Solution:
    def maxSum(self, nums: List[int]) -> int:
        answer = 0
        seen = [False for i in range(101)]
        for num in nums:
            if num > 0 and not seen[num]:
                seen[num] = True
                answer += num
        if answer:
            return answer
        return max(nums)

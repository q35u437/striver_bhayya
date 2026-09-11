class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor_of_all = 0
        for num in nums:
            xor_of_all ^= num
        #just find a bit where the two numbers differ
        differing_bit = -1
        for i in range(32):
            if xor_of_all & (1 << i) > 0:
                differing_bit = i
                break
        #divide groups by this bit
        answer = 0
        for num in nums:
            if num & (1 << differing_bit) > 0:
                answer = answer ^ num
        return [answer, xor_of_all ^ answer]

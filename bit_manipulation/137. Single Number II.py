class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        answer = 0
        for bit_position in range(32):
            counter = 0
            for num in nums:
                counter += 1 if (num & (1 << bit_position)) > 0 else 0
            if counter % 3 > 0:
                if bit_position == 31:
                    answer = answer - (1 << 31)
                else:
                    answer = answer | (1<<bit_position)
        return answer

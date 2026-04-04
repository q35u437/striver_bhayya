import math

class Solution:
    def minimumTime(self, d: List[int], r: List[int]) -> int:
        left = 1
        right = 4000000000
        answer = 4000000000
        LCM = math.lcm(r[0], r[1])
        while left < right:
            middle = (left + right) // 2
            if d[0] <= (middle - (middle // r[0])) and d[1] <= (middle - (middle // r[1])) and (d[0] + d[1]) <= (middle - (middle // LCM)):
                answer = min(answer, middle)
                right = middle
            else:
                left = middle + 1
        return answer

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        answer = 0
        negative = 1
        if dividend < 0:
            negative = -1
            dividend = abs(dividend)
        if divisor < 0:
            negative = -negative
            divisor = abs(divisor)
        while divisor <= dividend:
            x = 0
            while (dividend) >= (divisor << (x+1)):
                x += 1
            dividend -= (divisor << x)
            answer += (1 << x)
        answer = -answer if negative == -1 else answer
        if answer < -(2**31):
            return -(2**31)
        elif answer > (2**31 - 1):
            return (2**31 - 1)
        else:
            return answer

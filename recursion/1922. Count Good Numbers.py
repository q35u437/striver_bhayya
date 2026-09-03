class Solution:
    def getPower(self, number, power):
        if power == 0:
            return 1
        elif number == 0:
            return 0
        
        if power % 2 == 0:
            return self.getPower((number * number) % 1000000007, power // 2)
        else:
            return ( number * self.getPower(number, power-1) ) % 1000000007


    def countGoodNumbers(self, n: int) -> int:
        even_count = (n >> 1) + ( n & 1 )
        odd_count = n - even_count
        answer =  ( self.getPower(5, even_count) * self.getPower(4, odd_count) ) % 1000000007
        return answer

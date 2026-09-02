class Solution:
    def getAnswer(self, number, power):
        if power == 0:
            return 1
        elif power == 1:
            return number
        elif power % 2 == 0:
            return self.getAnswer(number * number, power // 2)
        elif power % 2 == 1:
            return number * self.getAnswer(number, power - 1)

    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            return 1 / self.getAnswer(x, -n)
        return self.getAnswer(x, n)

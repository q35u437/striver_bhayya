class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        total = 0
        empties = 0
        while True:
            total += (numBottles)
            empties += numBottles
            numBottles = 0
            if empties < numExchange:
                break
            numBottles = empties // numExchange
            empties = empties % numExchange
        return total

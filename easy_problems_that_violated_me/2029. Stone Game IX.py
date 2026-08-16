class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        if len(stones) == 1:
            return False
        counter_0 = counter_1 = counter_2 = 0
        for stone in stones:
            if stone % 3 == 0:
                counter_0 += 1
            elif stone % 3 == 1:
                counter_1 += 1
            else:
                counter_2 += 1
        # ((counter_1 - counter_2 == 2) and (counter_0 % 2 == 1))
        # ((counter_2 - counter_1 == 2) and (counter_0 % 2 == 1))
        # (counter_1 == 1 and counter_2 == 1 and (counter_0 % 2 == 0)) or 
        return ((counter_0 % 2 == 0 and counter_1 >= 1 and counter_2 >= 1) or (counter_0 % 2 == 1 and (counter_2 - counter_1 > 2)) or (counter_0 % 2 == 1 and (counter_1 - counter_2 > 2)))

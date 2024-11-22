class Solution:
    def checkBitSet(self, number, position):
        return number & (1<<position)
    def largestCombination(self, candidates: List[int]) -> int:
        answer = -float("inf")
        for position in range(0, 24):
            counter = 0
            for candidate in candidates:
                if self.checkBitSet(candidate, position):
                    counter += 1
            answer = max(answer , counter)
        return answer

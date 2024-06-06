class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        freq = {}
        answer = {}
        for number in hand:
            if number not in freq:
                freq[number] = 1
                answer[number] = False
            else:
                freq[number] += 1
        uniqueSorted = sorted(hand)
        for number in uniqueSorted:
            if freq[number]:
                for num in range(number, number+groupSize):
                    if num not in freq:
                        return False
                    else:
                        if freq[num] == 0:
                            return False
                        else:
                            freq[num] -= 1
        return True

"""
How the custom comparator works
When providing a custom comparator, it should generally return an integer/float value that follows the following pattern (as with most other programming languages and frameworks):

return a negative value (< 0) when the left item should be sorted before the right item
return a positive value (> 0) when the left item should be sorted after the right item
return 0 when both the left and the right item have the same weight and should be ordered "equally" without precedence
"""

from functools import cmp_to_key

class Solution:
    def compare(self, item1, item2):
        if item1[1] < item2[1]:
            return -1
        elif item1[1] > item2[1]:
            return 1
        else:
            return -(item1[0] - item2[0])
    def frequencySort(self, nums: List[int]) -> List[int]:
        d = {}
        for num in nums:
            if num not in d:
                d[num] = 1
            else:
                d[num] += 1
        array = [item for item in d.items()]
        array.sort(key = cmp_to_key(self.compare))
        answer = []
        for num, freq in array:
            for index in range(freq):
                answer.append(num)
        return answer

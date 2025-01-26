from collections import deque
class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        groups = []
        group_index = dict()
        for number in sorted(nums):
            if not groups or abs(groups[-1][-1]-number) > limit:
                groups.append(deque([number]))
            else:
                groups[-1].append(number)
            group_index[number] = len(groups) - 1
        answer = []
        for number in nums:
            group = group_index[number]
            answer.append(groups[group].popleft())
        return answer

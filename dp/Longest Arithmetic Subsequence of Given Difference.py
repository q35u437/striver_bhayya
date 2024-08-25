class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        d = {}
        answer = -float("inf")
        for ele in arr:
            if ele - difference in d:
                d[ele] = d[ele-difference] + 1
            else:
                d[ele] = 1
        return max(d.values())

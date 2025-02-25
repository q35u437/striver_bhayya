class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        odd_prefix_sum_count = 0
        even_prefix_sum_count = 0
        prefix_sum = 0
        answer = 0
        for a in arr:
            prefix_sum += a
            if prefix_sum % 2:
                answer += even_prefix_sum_count + 1
                odd_prefix_sum_count += 1
            else:
                answer += odd_prefix_sum_count
                even_prefix_sum_count += 1
        return answer % 1000000007

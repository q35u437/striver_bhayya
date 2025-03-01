class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        answer = -float("inf")
        dp_ = [[2 for i in range(len(arr))] for i in range(len(arr))]
        mp = {}
        for index in range(len(arr)):
            mp[arr[index]] = index
        for last_number in range(len(arr)):
            for last_but_one_number in range(last_number):
                last_nunchi_moododi_number = arr[last_number] - arr[last_but_one_number]
                if last_nunchi_moododi_number in mp and mp[last_nunchi_moododi_number] < last_but_one_number:
                    index = mp[last_nunchi_moododi_number]
                    dp_[last_number][last_but_one_number] = max(dp_[last_number][last_but_one_number], 1 + dp_[last_but_one_number][index])
                    answer = max(answer, dp_[last_number][last_but_one_number])
        if answer == -float("inf"):
            return 0       
        return answer

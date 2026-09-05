class Solution:
    def checkPallindrome(self, string):
        length = len(string) // 2
        for index in range(length):
            if string[index] != string[len(string)-index-1]:
                return False 
        return True
    
    def getAnswer(self, string, number_of_split_points, current_number_of_split_points, prev_index, temp, answer):
        if number_of_split_points == current_number_of_split_points:
            substring = string[prev_index+1: ]
            if substring:
                if self.checkPallindrome(substring):
                    kk = tuple(temp + [substring])
                    if kk not in answer:
                        answer.add(kk)
                else:
                    return
            elif temp:
                kk = tuple(temp)
                if kk not in answer:
                    answer.add(kk)
        else:
            for index in range(prev_index + 1, len(string)):
                substring = string[prev_index+1: index + 1]
                if self.checkPallindrome(substring):
                    temp.append(substring)
                    self.getAnswer(string, number_of_split_points, current_number_of_split_points + 1, index, temp, answer)
                    temp.pop()

    def partition(self, s: str) -> List[List[str]]:
        answer = set()
        for partition_length in range(1, len(s)+1):
            number_of_split_points = partition_length - 1
            if number_of_split_points == len(s) - 1:
                answer.add((char for char in s))
            else:
                self.getAnswer(s, number_of_split_points, 0, -1, [], answer)
        return [list(kk) for kk in answer]

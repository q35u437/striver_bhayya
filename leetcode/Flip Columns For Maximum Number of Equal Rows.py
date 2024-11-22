class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        answer = -1
        for r1 in range(0, len(matrix)):
            counter = 1
            for r2 in range(r1+1, len(matrix)):
                if matrix[r1] == matrix[r2]:
                    counter += 1
                else:
                    for c1 in range(0, len(matrix[0])):
                        if matrix[r1][c1] == matrix[r2][c1]:
                            break
                    else:
                        counter += 1
            answer = max(answer, counter)
        return answer

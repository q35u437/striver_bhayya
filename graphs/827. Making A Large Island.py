from collections import deque
class Solution:
    def BFS(self, grid, maxArea, cr, cc, counter):
        q = deque([(cr, cc)])
        total = 1
        visited = set([(cr, cc)])
        while q:
            node = q.popleft()
            for dx, dy in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                if node[0] + dx >= 0 and node[0] + dx < len(grid) and node[1] + dy >= 0 and node[1] + dy < len(grid) and (node[0] + dx, node[1] + dy) not in visited and grid[node[0] + dx][node[1] + dy]:
                    q.append((node[0] + dx, node[1] + dy))
                    visited.add((node[0] + dx, node[1] + dy))
                    total += 1
        for cr, cc in visited:
            maxArea[cr][cc] = (total, counter[0])
        counter[0] += 1


    def largestIsland(self, grid: List[List[int]]) -> int:
        maxArea = [[(0, -1) for j in range(len(grid))] for i in range(len(grid))]
        counter = [0]
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j] and maxArea[i][j][0] == 0:
                    self.BFS(grid, maxArea, i, j, counter)
        answer = -1
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j] == 0:
                    total = 0
                    s = set()
                    for dx, dy in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                        if i + dx >= 0 and i + dx < len(grid) and j + dy >= 0 and j + dy < len(grid) and maxArea[i+dx][j+dy][1] not in s:
                            total += maxArea[i+dx][j+dy][0]
                            s.add(maxArea[i+dx][j+dy][1])
                    answer = max(answer, 1 + total)
                else:
                    answer = max(answer, maxArea[i][j][0])
        return answer

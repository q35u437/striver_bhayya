from collections import deque
class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        visited = set((0, 0))
        queue = deque([((0,0), 0)])
        while queue:
            node, length = queue.popleft()
            x, y = node[0], node[1]

            if x == len(grid)-1 and y == len(grid[0])-1:
                return length

            if x > 0 and (x-1, y) not in visited:
                if grid[x-1][y]:
                    queue.append(((x-1, y), length+1))
                else:
                    queue.appendleft(((x-1, y), length))
                visited.add((x-1, y))
            
            if x < len(grid)-1 and (x+1, y) not in visited:
                if grid[x+1][y]:
                    queue.append(((x+1, y), length+1))
                else:
                    queue.appendleft(((x+1, y), length))
                visited.add((x+1, y))
            
            if y > 0 and (x, y-1) not in visited:
                if grid[x][y-1]:
                    queue.append(((x, y-1), length+1))
                else:
                    queue.appendleft(((x, y-1), length))
                visited.add((x, y-1))
            
            if y < len(grid[0])-1 and (x, y+1) not in visited:
                if grid[x][y+1]:
                    queue.append(((x, y+1), length+1))
                else:
                    queue.appendleft(((x, y+1),length))
                visited.add((x, y+1))

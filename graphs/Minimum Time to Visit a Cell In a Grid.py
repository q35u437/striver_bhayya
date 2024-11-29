class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][0] - grid[0][1] < -1 and grid[0][0] - grid[1][0] < -1:
            return -1
        
        m = len(grid)
        n = len(grid[0])
        pq = [(0, (0, 0))]
        dxy = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        visited = set([(0, 0)])
        while pq:
            timetaken, node = heapq.heappop(pq)
            if node == (m-1, n-1):
                return timetaken
            for dxxyy in dxy:
                nx, ny = (node[0] + dxxyy[0], node[1] + dxxyy[1])
                if(nx >= 0 and nx < m and ny >= 0 and ny < n) and (nx, ny) not in visited:
                    if (timetaken) >= grid[nx][ny]-1:
                        heapq.heappush(pq, (timetaken+1, (nx, ny)))
                    else:
                        if (grid[nx][ny]-timetaken) % 2:
                            heapq.heappush(pq, (grid[nx][ny], (nx, ny)))
                        else:
                            heapq.heappush(pq, (grid[nx][ny]+1, (nx, ny)))
                    visited.add((nx, ny))

                            

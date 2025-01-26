from collections import deque
class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        length = len(favorite)
        in_degrees = [0 for i in range(length)]
        max_depths = [0 for i in range(length)]
        for fav in favorite:
            in_degrees[fav] += 1
        q = deque()
        for i in range(length):
            if in_degrees[i] == 0:
                q.append(i)
        while q:
            node = q.popleft()
            neighbour = favorite[node]
            max_depths[neighbour] = max(max_depths[neighbour], max_depths[node] + 1)
            in_degrees[neighbour] -= 1
            if in_degrees[neighbour] == 0:
                q.append(neighbour)
        max_length = twoCycles = 0
        for i in range(length):
            if in_degrees[i] == 0:
                continue
            cycle_length = 0
            j = i
            while in_degrees[j] != 0:
                cycle_length += 1
                in_degrees[j] = 0
                j = favorite[j]
            if cycle_length > 2:
                max_length = max(max_length, cycle_length)
            elif cycle_length == 2:
                twoCycles += (max_depths[i] + max_depths[favorite[i]] + 2)
        return max(max_length, twoCycles)

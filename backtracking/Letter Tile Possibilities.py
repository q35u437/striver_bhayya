class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        count = Counter(tiles)
        print(count)
        def backtrack():
            result = 0
            for c in count:
                if count[c] > 0:
                    count[c] -= 1
                    result += 1
                    result += backtrack()
                    count[c] += 1
            return result
        return backtrack()

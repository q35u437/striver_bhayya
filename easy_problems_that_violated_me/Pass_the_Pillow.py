def passThePillow(self, n: int, time: int) -> int:
    n -= 1
    if time % n == 0:
        if (time // n)%2:
            return n+1
        else:
            return 1
    else:
        if (time // n)%2:
            return n - (time % n) + 1
        else:
            return (time % n) + 1

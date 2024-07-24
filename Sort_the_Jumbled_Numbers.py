def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
    def compare(number):
        if number == 0:
            return mapping[number]
        result = 0
        f = 1
        while number:
            number , rem = divmod(number, 10)
            result += (mapping[rem] * f)
            f *= 10

        return result
    nums.sort(key = compare)
    return nums

class Solution(object):
    def abbreviateProduct(self, a, b):
        value, count_zeros, digit_shift = 1.0, 0, 0
        remainder = 1
        for num in range(a, b + 1):
            value *= num
            while value >= 1:
                value /= 10
                digit_shift += 1
            remainder *= num
            while remainder % 10 == 0:
                count_zeros += 1
                remainder //= 10
            if remainder > 10 ** 14:
                remainder %= 10 ** 14
        if digit_shift - count_zeros <= 10:
            return str(int(value * (10 ** (digit_shift - count_zeros)) + 0.5)) + 'e' + str(count_zeros)
        else:
            return str(int(value * 100000)) + '...' + ('0000' + str(remainder))[-5:] + 'e' + str(count_zeros)
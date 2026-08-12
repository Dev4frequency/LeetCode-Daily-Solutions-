from math import lcm

class Solution:
    def minimizeSet(self, divisor1: int, divisor2: int, count1: int, count2: int) -> int:
        
        calculate_positive = lambda x: (x + abs(x)) // 2

        total_elements, previous_value, common_multiple = count1 + count2, 0, lcm(divisor1, divisor2)

        while total_elements > previous_value:
            previous_value = total_elements

            remaining_count1, remaining_count2 = total_elements // divisor2 - total_elements // common_multiple, total_elements // divisor1 - total_elements // common_multiple

            total_elements += calculate_positive(calculate_positive(count1 - remaining_count1) + calculate_positive(count2 - remaining_count2) - total_elements + total_elements // common_multiple + remaining_count2 + remaining_count1)

        return total_elements
class Solution:
    def intToRoman(self, num: int) -> str:
        old_symbol_dict = {
            'M': 1000,
            'CM': 900,
            'D': 500,
            'CD': 400,
            'C': 100,
            'XC': 90,
            'L': 50,
            'XL': 40,
            'X': 10,
            'IX': 9,
            'V': 5,
            'IV': 4,
            'I': 1
        }

        result = ''
        while num > 0:
            for symbol, value in old_symbol_dict.items():
                while num >= value:
                    num -= value
                    result += symbol

        return result

s = Solution()

print(s.intToRoman(3))
print(s.intToRoman(58))
print(s.intToRoman(1994))

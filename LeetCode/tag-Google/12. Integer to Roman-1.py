class Solution:
    def intToRoman(self, num: int) -> str:
        old_symbol_dict = {
            'M': 1000,
            'D': 500,
            'C': 100,
            'L': 50,
            'X': 10,
            'V': 5,
            'I': 1
        }

        result = ''
        while num > 0:
            for symbol, value in old_symbol_dict.items():
                while num >= value:
                    num -= value
                    result += symbol

        new_symbol_dict = {
            'VIIII': 'IX',
            'IIII': 'IV',
            'LXXXX': 'XC',
            'XXXX': 'XL',
            'DCCCC': 'CM',
            'CCCC': 'CD',
        }

        for old_symbol, new_symbol in new_symbol_dict.items():
            result = result.replace(old_symbol, new_symbol)

        return result

s = Solution()

print(s.intToRoman(3))
print(s.intToRoman(58))
print(s.intToRoman(1994))

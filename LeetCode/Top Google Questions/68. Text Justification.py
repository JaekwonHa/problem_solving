from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        answer = []

        temp = []
        tempLength = 0
        for word in words:
            if len(temp) == 0:
                temp.append(word)
                tempLength = len(word)
                continue

            if tempLength + len(word) + len(temp) <= maxWidth:
                temp.append(word)
                tempLength += len(word)
            else:
                if len(temp) == 1:
                    remain_base = maxWidth - tempLength
                    result = temp[0] + ' '*remain_base
                    answer.append(result)
                else:
                    need_space = len(temp)-1
                    remain_base = (maxWidth - tempLength) // need_space
                    remain_one = (maxWidth - tempLength) % need_space

                    result = temp[0]

                    for s in temp[1:]:
                        if remain_one > 0:
                            result += ' '
                            remain_one -= 1
                        result += ' '*remain_base + s

                    answer.append(result)

                temp = [word]
                tempLength = len(word)

        # process last element
        if len(temp) > 0:
            result = ' '.join(temp)
            remain_base = maxWidth - len(result)
            result += ' '*remain_base
            answer.append(result)

        return answer


s = Solution()
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
print(s.fullJustify(words, maxWidth))

words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
print(s.fullJustify(words, maxWidth))


digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

class Solution:
    def decodeString(self, s: str) -> str:
        global digits

        st = []

        answer = []
        for i in range(len(s)):
            if len(st) == 0:
                st.append(s[i])
                continue

            if s[i] == ']':
                encoded_string = ''
                while len(st) > 0 and st[-1] != '[':
                    encoded_string += st[-1]
                    st.pop()
                st.pop()

                k = ''
                while len(st) > 0 and st[-1] in digits:
                    k += st[-1]
                    st.pop()
                k = int(k[::-1])

                encoded_string = ''.join(k * encoded_string[::-1])
                for ii in range(len(encoded_string)):
                    st.append(encoded_string[ii])
                continue

            st.append(s[i])

        return ''.join(st)


s = Solution()
input = "3[a]2[bc]"
print(s.decodeString(input))


input = "3[a2[c]]"
print(s.decodeString(input))


input = "2[abc]3[cd]ef"
print(s.decodeString(input))

input = "100[leetcode]"
print(s.decodeString(input))

input = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef"
print(s.decodeString(input))

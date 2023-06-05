class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        st = []
        answer = 0

        for c in s:
            if c == '(':
                st.append(c)
                continue

            if len(st) != 0 and st[-1] == '(':
                st.pop()
                continue
            else:
                answer += 1
        return answer + len(st)

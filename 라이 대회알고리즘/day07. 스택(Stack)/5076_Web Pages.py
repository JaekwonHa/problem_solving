import sys
readline=sys.stdin.readline


def step1(content: str):
    st = []
    i = 0
    while i < len(content):
        c = content[i]
        if c == '<':
            j = i + 1
            while content[j] != '>':
                j += 1
            j += 1
            if j > len(content):
                return "illegal"
            tag = content[i:j]
            i = j-1
            if len(st) == 0:
                st.append(tag)
                i += 1
                continue
            if tag.endswith("/>"):
                i += 1
                continue
            if tag.startswith("</"):
                close_tag = tag[2:-1]
                if st[-1].startswith(f"<{close_tag}"):
                    st.pop()
                    i += 1
                    continue
                else:
                    return "illegal"
            st.append(tag)
        i += 1
    return "legal" if len(st) == 0 else "illegal"


if __name__ == '__main__':

    while True:
        content = readline().replace('\n', '')
        if content == "#":
            break
        print(step1(content))

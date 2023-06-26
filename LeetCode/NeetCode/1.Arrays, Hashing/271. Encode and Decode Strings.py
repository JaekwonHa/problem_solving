from typing import List

class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        return "👍".join(strs)

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        return s.split('👍')

# Your Codec object will be instantiated and called as such:
strs = ["Hello", "World"]

codec = Codec()
print(codec.decode(codec.encode(strs)))

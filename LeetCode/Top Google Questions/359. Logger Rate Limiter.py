from collections import defaultdict


class Logger:

    def __init__(self):
        self.hash = defaultdict(int)

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        available_timestamp = self.hash[message]
        if available_timestamp <= timestamp:
            self.hash[message] = timestamp+10
            return True
        return False




# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)
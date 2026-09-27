class MinStack:
    def __init__(self) -> None:
        self.stack = []
        self.min_stack = [float('inf')]  # Initialize with infinity as sentinel value

    def push(self, val: int) -> None:
        self.stack.append(val)
        # Keep track of minimum by comparing with current minimum
        self.min_stack.append(min(val, self.min_stack[-1]))

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

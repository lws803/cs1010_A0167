class stack(object):
    def __init__(self):
        self.stack = []

    def size(self):
        return len(self.stack)

    def push(self,data):
        self.stack.insert(0,data)

    def pop(self):
        return self.stack.pop(0)

    def isEmpty(self):
        return len(self.stack) == 0   

def denary_to_binary(decNumber):
    processingStack = stack()
    while decNumber > 0:
        remainder = decNumber % 2
        processingStack.push(remainder)
        decNumber = decNumber // 2

    binary = ''
    while not processingStack.isEmpty():
        binary += str(processingStack.pop())
    return binary

print(denary_to_binary(78))

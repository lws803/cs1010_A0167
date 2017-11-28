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

def baseConverter(decNumber,base):
    digits = "0123456789ABCDEF"
    processingStack = stack()
    while decNumber > 0:
        remainder = decNumber % base
        processingStack.push(digits[remainder])
        decNumber = decNumber // base

    number = ''
    while not processingStack.isEmpty():
        number += str(processingStack.pop())

    return number

print(baseConverter(220,16))
print(baseConverter(220,16))

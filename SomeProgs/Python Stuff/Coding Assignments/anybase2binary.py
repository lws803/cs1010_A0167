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

def anybase2binary(binaryNo,base):
    digits = '0123456789ABCDEF'
    binary = ''
    for i in binaryNo:
        binStack = stack()

        ##Finding value
        index = digits.index(i)

        if base == 16:
            number = 4
        elif base == 8:
            number = 3

        while number > 0:
            if index > 0:
                remainder = index % 2
                binStack.push(remainder)
                index = index // 2
            else:
                binStack.push(0)
            number -= 1
        while not binStack.isEmpty():
            binary += str(binStack.pop())

    return binary

print(anybase2binary("CAD",16))

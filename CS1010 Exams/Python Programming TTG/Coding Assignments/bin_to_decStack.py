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

def bin_to_dec(binaryNo):
    binStack = stack()
    for i in str(binaryNo):
        binStack.push(i)

    decNo = 0
    power = 0
    while not binStack.isEmpty():
        decNo += int(binStack.pop())* 2**power
        power += 1

    return decNo

print(bin_to_dec(10001011))

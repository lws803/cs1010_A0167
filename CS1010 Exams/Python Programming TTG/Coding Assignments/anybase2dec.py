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
    dec = 0
    numberStack = stack()

    for i in binaryNo:
        value = digits.index(i)
        numberStack.push(value)

    power = 0
    while not numberStack.isEmpty():
        dec += numberStack.pop() * base**power

    return dec

print(anybase2binary("D4",16))
print(anybase2binary("E7",16))

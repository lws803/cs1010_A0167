class Stack(object):
    def Create(self, data = [],top = None):
        self.data = data
        self.length = 0
        self.top = top
        
    def isEmpty(self):
        return self.length == 0
    
    def Push(self,item):
        self.data.append(item)
        self.length += 1
        self.top = self.length - 1

    def Pop(self):
        if self.isEmpty():
            return "ERROR: "
        top = self.top
        self.length -= 1
        self.top = self.length - 1
        return self.data.pop(top)

    def Peep(self):
        return self.data[self.length -1]

def CheckNested(construct):
    stack = Stack()
    stack.Create()
    brackets = {'[':']','(':')','{':'}'}
    rev_brackets = {']':'[',')':'(','}':'{'}

    for i in construct:
        if i in brackets.keys():
            stack.Push(i)
        else:
            if stack.isEmpty():
                print("ERROR: No more left brackets. expecting '{0}'.".format(rev_brackets[i]))
                return False
            left = stack.Pop()
            if brackets[left] == i:
                continue
            else:
                print("ERROR: Wrong right bracket. expecting '{0}'.".format(brackets[left]))
                return False
    if stack.isEmpty():
        return True
    else:
        print("ERROR: Excess left brackets. expecting '{0}'.".format(brackets[stack.Pop()]))
        return False

def CheckWellformed(construct):
    stack = Stack()
    stack.Create()
    brackets = {'[':']','(':')','{':'}'}
    rev_brackets = {']':'[',')':'(','}':'{'}

    for i in construct:
        if i in brackets.keys():
            stack.Push(i)
        else:
            if stack.isEmpty():
                print("ERROR: No more left brackets. expecting '{0}'.".format(rev_brackets[i]))
                return False
            left = stack.Pop()
            if brackets[left] == i:
                continue
            else:
                print("ERROR: Wrong right bracket. expecting '{0}'.".format(brackets[left]))
                return False
    if stack.isEmpty():
        return True
    else:
        print("ERROR: Excess left brackets. expecting '{0}'.".format(brackets[stack.Pop()]))
        return False

print(CheckNested("(())"))

def main():
    infile = open("DATA.txt","r")
    data = infile.readlines()
    outfile = open("ERRORS.txt","w")
    for i in data:
        print(i[:-1])
        if not CheckNested(i[:-1]):
            print(i[:-1],file = outfile)
    infile.close()
    outfile.close()
    print

    error = open("ERRORS.txt","r")
    errors = error.readlines()
    for i in errors:
        CheckWellformed(i)
    error.close()
main()
    

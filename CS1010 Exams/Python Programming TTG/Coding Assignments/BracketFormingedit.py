class Stack(object):
    def __init__(self):
        self.data = None
        self.top = None    
    
    def Create(self):
        self.data = []
        self.Top = 0

    def Push(self,item):
        self.data.append(item)
        self.Top += 1

    def Pop(self):
        if self.Top == 0:
            return "No items in List"
        else:
            self.Top -= 1
            return self.data.pop()

    def Peep(self):
        if self.Top == 0:
            return None
        return self.data[self.Top - 1]

    def isEmpty(self):
        return self.Top == 0

def CheckNested(construct):
    checkStack = Stack()
    checkStack.Create()
    outfile = open("ERRORS.txt","a")
    brackets = {"{":"}","(":")","[":"]"}

    for i in construct:
        if i == "{" or i == "(" or i == "[":
            checkStack.Push(i)
        elif i in brackets:
            if checkStack.Peep() == "{":
                checkStack.Pop()
            else:
                return "{0} is not well-formed".format(construct)
        elif i == "]":
            if checkStack.Peep() == "[":
                checkStack.Pop()
            else:
                return "{0} is not well-formed".format(construct)
        elif i == ")":
            if checkStack.Peep() == "(":
                checkStack.Pop()
            else:
                return "{0} is not well-formed".format(construct)

    if checkStack.isEmpty():
        outfile.close()
        return "{0} is well-formed".format(construct)
        
    else:
        print(construct,file = outfile)
        outfile.close()
        return "{0} is not well-formed".format(construct)
    
def CheckWellformed(construct):
    checkStack = Stack()
    checkStack.Create()
    outfile = open("ERRORS.txt","a")
    brackets = {"}":"{", ")":"(", "]":"["}
    inv_brackets = {"{":"}", "(":")", "[":"]"}

    for i in construct:
        if i in inv_brackets:
            checkStack.Push(i)
        elif i in brackets:
            left_bracket = checkStack.Pop()
            if left_bracket == brackets[i]:
                continue
            else:
                if left_bracket in inv_brackets:
                    return "{0} is not well-formed, Expecting '{1}'.".format(construct,inv_brackets[left_bracket])                    
                else:
                    return "{0} is not well-formed, Expecting '{1}'.".format(construct,brackets[i])
            
    if checkStack.isEmpty():
        outfile.close()
        return "{0} is well-formed".format(construct)
        
    else:
        outfile.close()
        return "{0} is not well-formed, Expecting '{1}'.".format(construct,inv_brackets[left_bracket])

def main():
    infile = open("DATA.txt","r")
    data = infile.readlines()
    temp_list = []
    for i in data:
        temp_list.append(i[:-1])
    for i in temp_list:
        print(CheckWellformed(i))
main()

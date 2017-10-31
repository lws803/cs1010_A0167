class Node(object):
    def __init__(self,Data = str(''),LeftP = int(-1),RightP = int(-1)):
        self.Data = Data
        self.LeftP = LeftP
        self.RightP = RightP

    def get_Data(self):
        return self.Data
    def set_Data(self,new):
        self.Data = new

    def get_LeftP(self):
        return self.LeftP
    def set_LeftP(self,new):
        self.LeftP = new

    def get_RightP(self):
        return self.RightP
    def set_RightP(self,new):
        self.RightP = new

array = []
for i in range(20):
    if i == 19:
        array.append(Node('',-1,-1))
    else:
        array.append(Node('',i+1,-1))

root = -1
free = 0
maximum = 20
length = 0

def print_left():
    global array
    for j in array:
        print(j.get_LeftP())
def print_right():
    global array
    for j in array:
        print(j.get_RightP())
def print_all():
    global array
    for j in array:
        print('{0},{1},{2}'.format(j.get_LeftP(),j.get_Data(),j.get_RightP()))
def AddItemToBinaryTree(NewTreeItem):
    global array,root,free,maximum,length
    array[free].set_Data(NewTreeItem)
    current = root
    nextFree = array[free].get_LeftP()
    if length < maximum:
        if length == 0:
            root = free
            free = array[root].get_LeftP()
            array[root].set_LeftP(-1)
        else:
            #TRAVERSE
            current = root
            previous = current
            last = 'X'
            while current != -1:
                if NewTreeItem > array[current].get_Data():
                    previous = current
                    current = array[current].get_RightP()
                    last = 'R'
                else:
                    previous = current
                    current = array[current].get_LeftP()
                    last = 'L'
            if last == 'R':
                array[previous].set_RightP(free)
            elif last == 'L':
                array[previous].set_LeftP(free)
            array[free].set_LeftP(-1)
            free = nextFree
            
        length += 1
    else:
        print("No space")

def OutputData(array,current):
    if current != -1:
        OutputData(array,array[current].get_LeftP())
        print(array[current].get_Data())
        OutputData(array,array[current].get_RightP())

def main():
    global array,root,free,maximum,length
    more = True
    while more:
        response = input("Country Name:")
        if response == "XXX":
            more = False
            break
        AddItemToBinaryTree(response)
    OutputData(array,root)
main()
        


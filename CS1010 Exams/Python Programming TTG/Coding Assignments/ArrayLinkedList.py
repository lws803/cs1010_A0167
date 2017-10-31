class Node(object):
    def __init__(self,data = None,ptr = None):
        self.data = data
        self.ptr = ptr

class LinkedList(object):
    def __init__(self,maxsize):
        self.start = 0
        self.nextfree = 0
        self.array = []
        self.maxsize = maxsize
        self.freeLength = maxsize
        self.dataLength = 0
        for i in range(maxsize):
            self.array.append(Node("",i + 1))
            if i == maxsize - 1:
                self.array.append(Node("",-1))

    def prtList(self):
        text = ''
        current = self.start
        while self.array[current].ptr != -1:
            text += "|{0}|->".format(self.array[current].data)
            current = self.array[current].ptr
        return text
    
    def addNode(self):
        invalid_item = True
        while invalid_item:
            item = input("Enter data to insert: ")
            if item == "":
                invalid_item = True
            else:
                invalid_item = False
        
        if self.freeLength == 0:
            return "Not enough memory in the Freelist"
        else:
            self.array[self.nextfree].data = item
            
            if item < self.array[self.start].data:
                temp = self.nextfree
                self.nextfree = self.array[self.nextfree].ptr
                temp.ptr = -1
                self.start = temp
                self.dataLength += 1
                self.freeLength -= 1

            current = self.start
            previous = self.start
            while self.array[current].ptr != -1 and item > self.array[current].data:
                previous = current
                current = self.array[current].ptr
            if item > self.array[current].data and self.array[current].ptr == -1:
                temp = self.nextfree
                self.nextfree = self.array[self.nextfree].ptr
                self.array[temp].ptr = None
                self.array[current].ptr = temp
                self.dataLength += 1
                self.freeLength -= 1
            else:
                temp = self.nextfree
                self.nextfree = self.array[self.nextfree].ptr
                self.array[temp].ptr = current
                self.array[previous].ptr = temp
                self.dataLength += 1
                self.freeLength -= 1

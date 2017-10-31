class node(object):
    def __init__(self,data = None,ptr = None):
        self.data = data
        self.ptr = ptr

class linkedList(node):
    def __init__(self):
        Node = node()
        self.first = Node
        self.length = 0

    def __str__(self):
        if self.length == 0:
            return "There is no data in the linked list."
        elif self.length == 1:
            return "{0}->".format(self.first.data)
        else:
            text = ''
            noNodes = self.length
            currentNode = self.first
            while noNodes > 0:
                text += "{0}->".format(currentNode.data)
                currentNode = currentNode.ptr
                noNodes -= 1
            return text

    def createList(self,num):
        while num > 0:
            Node = node()
            Node.ptr = self.first
            self.first = Node
            num -= 1
            self.length += 1

    def insertNode(self,newlist):
        if newlist.length == 0:
            return "No more memory to insert anymore nodes."
        else:
            newData = input("Enter data to be inserted: ")
            newlist.first.data = newData
            if self.length == 0:
                self.first = newlist.first
                newlist.first = newlist.first.ptr
                self.first.ptr = None
                self.length += 1
                newlist.length -= 1
            else:
                if newData < self.first.data:
                    temp = newlist.first
                    newlist.first = newlist.first.ptr
                    temp.ptr = self.first.ptr
                    self.first = temp
                    self.length += 1
                    newlist.length -= 1
                else:
                    previousNode = self.first
                    currentNode = self.first
                    while currentNode.ptr != None and newData > currentNode.data:
                        previousNode = currentNode
                        currentNode = currentNode.ptr
                    if newData > currentNode.data and currentNode.ptr == None:
                        temp = newlist.first
                        newlist.first = newlist.first.ptr
                        currentNode.ptr = temp
                        temp.ptr = None
                        self.length += 1
                        newlist.length -= 1
                    else:
                        temp = newlist.first
                        newlist.first = newlist.first.ptr
                        previousNode.ptr = temp
                        temp.ptr = currentNode
                        self.length += 1
                        newlist.length -= 1

    def removeNode(self,newlist):
        if self.length == 0:
            return "No data in the datalist to remove."
        else:
            dataitem = input("Enter the data to be removed: ")
            if dataitem == self.first.data:
                temp = self.first
                self.first = self.first.ptr
                temp.ptr = newlist.first
                newlist.first = temp
                self.length -= 1
                newlist.length += 1
            else:
                previousNode = self.first
                currentNode = self.first
                while currentNode.ptr != None:
                    previousNode = currentNode
                    currentNode = currentNode.ptr
                if currentNode.ptr == None and dataitem != currentNode.data:
                    return "Data not found"
                elif dataitem == currentNode.data and currentNode.ptr != None:
                    temp = currentNode
                    previousNode.ptr = currentNode.ptr
                    temp.ptr = newlist.first
                    newlist.first = temp
                    self.length -= 1
                    newlist.length += 1

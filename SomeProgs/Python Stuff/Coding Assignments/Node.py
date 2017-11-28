class Node(object):
    def __init__(self,data = None,ptr = None):
        '''Node with data and pointer'''
        self.data = data
        self.ptr = ptr

    def __str__(self):
        '''String representation of the data'''
        return str(self.data)

class LinkedList(Node):
    def __init__(self):
        node = Node(None,None)
        self.first = node
        self.length = 0

    def __len__(self):
        return self.length

    def isEmpty(self):
        if self.length == 0:
            return True
        else:
            return False

    def __str__(self):
        current = self.first
        text = ""
        for i in range(self.length):
            text += "|{0}|->".format(current.data)
            current = current.ptr
        return text

    def insertfront(self,data):
        node = Node(data)
        if self.isEmpty():
            self.first = node
            self.length += 1
        else:
            temp = self.first
            self.first = node
            node.ptr = temp
            self.length += 1

    def insertlast(self,data):
        node = Node(data)
        if self.isEmpty():
            self.first = node
            self.length += 1
        else:
            current = self.first
            while current.ptr != None:
                current = current.ptr
            if current.ptr == None:
                current.ptr = node
                self.length += 1

    def removefirst(self):
        if self.isEmpty():
            return "WARNING: List is empty. IMPOSSIBLE!!!!!"
        else:
            self.first = self.first.ptr
            self.length -= 1

    def removelast(self):
        if self.isEmpty():
            return "WARNING: List is empty. IMPOSSIBLE!!!!!"
        else:
            current = self.first
            previous = self.first
            while current.ptr != None:
                previous = current
                current = current.ptr
            previous.ptr = None
            self.length -= 1

    def create_list(self,size):
        for i in range(size):
            self.insertlast("{0}".format(i+1))

    def insertFirstFree(self,other,newdata):
        other.first.data = newdata
        if self.isEmpty():
            temp = other.first
            self.first = temp
            other.first = other.first.ptr
            self.first.ptr = None
            self.length += 1
            other.length -= 1
        else:
            current = self.first
            while current.ptr != None:
                current = current.ptr
            if current.ptr == None:
                temp = other.first
                current.ptr = temp
                other.first = other.first.ptr
                current.ptr.ptr = None
                self.length += 1
                other.length -= 1

    def removeToFree(self,other):
        item = input("Enter data to remove: ")
        self.searchlist(item)

    def searchlist(self,item):
        current = self.first
        elementfound = False
        while current.ptr != None and (not elementfound):
            if str(current.data) == str(item):
                elementfound = True
            current = current.ptr
            
        if current.data == item:
            elementfound = True
                
        if elementfound == True:
            print("FOUND")
        else:
            print("NOT FOUND")
            
    def removeToFree(self,other,olddata):
        elementfound = False
        if self.first == None:
            print("List is empty")
            return
        if self.first.data == olddata:
            temp = self.first.ptr
            self.first.ptr = other.first
            other.first = self.first
            self.first = temp
            self.length -= 1
            other.length += 1

        else:
            current = self.first
            previous = self.first
            while current.data != olddata:
                previous = current
                current = current.ptr
            if current.data == olddata:
                temp = current.ptr
                previous.ptr = current.ptr
                current.ptr = other.first
                other.first = current
                self.length -= 1
                other.length += 1
                elementfound = True
        if elementfound == False:
            print("ERROR: Item not found in the Linked List!")
        if elementfound == True:
            print("Nextfree List: ")
            print(other)
            print("Data List:")
            print(self)
            print()

    def insertNode(self,other,newdata):
        if other.first == None:
            print("WARNING: No more space to insert more nodes!")
            return
        
        other.first.data = newdata
        if self.isEmpty():
            temp = other.first
            self.first = temp
            other.first = other.first.ptr
            self.first.ptr = None
            self.length += 1
            other.length -= 1
        elif newdata < self.first.data:
            temp = other.first
            other.first = other.first.ptr
            temp.ptr = self.first
            self.first = temp
            self.length += 1
            other.length -= 1
        else:
            previous = self.first
            current = self.first
            while current.ptr != None and newdata > current.data:
                previous = current
                current = current.ptr
            if newdata > current.data and current.ptr == None:
                temp = other.first
                current.ptr = temp
                other.first = other.first.ptr
                current.ptr.ptr = None
                self.length += 1
                other.length -= 1
            else:
                temp = other.first
                other.first = other.first.ptr
                temp.ptr = current
                previous.ptr = temp
                self.length += 1
                other.length -= 1
        print("Nextfree List:")
        print(other)
        print("Data List:")
        print(self)
                
def main():
    #Implement 20 nodes in freelist.
    nextfree = LinkedList()
    nextfree.create_list(2)

    #Create empty datalist
    data = LinkedList()
    data.create_list(0)

##    #Insert 5 nodes into the datalist from the freelist
##    i = 1
##    while i <= 5:
##        response = input("Enter new data: ")
##        nextfree.first.data = response
##        data.insertFirstFree(nextfree)
##        i += 1
##    print(data)
##    print(data.length)
##    print(nextfree.length)
##    
##    #implement search method to find data and return FOUND or NOT FOUND
##    data.searchlist()
##    
##    #Delete a node with data and return to free list
##    data.removeToFree(nextfree)
##    print(data.length)
##    print(data)
##    print(nextfree)
    print("Nextfree List:")
    print(nextfree)
    print("Data List:")
    print(data)
    print()
    choice = True
    while choice:
        print("Choose an action:")
        print("Choice 1: Insert a node")
        print("Choice 2: Delete a node")
        print("Choice 3: Search for a node")
        print("Choice 4: Exit the program.\n")
        choice = input("Enter choice: ")
        if choice == "1":
            print("Choice 1 selected: Insert Node.")
            newdata = input("Enter item to insert into the list: ")
            data.insertNode(nextfree,newdata)
            print()
            
        elif choice == "2":
            print("Choice 2 selected: Delete Node.")
            olddata = input("Enter item to be deleted from the list: ")
            data.removeToFree(nextfree,olddata)
            print()

        elif choice == "3":
            print("Choice 3 selected: Search for node.")
            search = input("Enter item to be searched: ")
            data.searchlist(search)

        elif choice == "4":
            print("Exiting the program.")
            choice = False
main()

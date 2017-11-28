class Node(object):
    def __init__(self,name = '',time = 0.0,ptr = None):
        self.Name = str(name)
        self.Time = float(time)
        self.Next = ptr

    def get_name(self):
        return self.Name
    def set_name(self,new):
        self.Name = new

    def get_time(self):
        return self.Time
    def set_time(self,new):
        self.Time = new

    def get_ptr(self):
        return self.Next
    def set_ptr(self,new):
        self.Next = new

class LinkedList(object):
    def __init__(self):
        self.length = 0
        self.head = Node()
    def isEmpty(self):
        return self.length == 0
    def Display(self):
        text = ''
        current = self.head
        while current.get_ptr() != None:
            current = current.get_ptr()
            temp = "|{0},{1}|\n".format(current.get_name(),current.get_time())
            text += temp
        return text
    def AddFirst(self,name = '',time = 0.0):
        newnode = Node(name,time)
        if self.isEmpty():
            self.head.set_ptr(newnode)
            self.length += 1
        else:
            newnode.set_ptr(self.head.get_ptr())
            self.head.set_ptr(newnode)
            self.length += 1
    def RemoveFirst(self):
        if self.isEmpty():
            print("ERROR: UNDERFLOW")
        else:
            self.head.set_ptr((self.head.get_ptr()).get_ptr())
            self.length -= 1
    def AddLast(self,name='',time=0.0):
        newnode = Node(name,time)
        if self.isEmpty():
            self.head.set_ptr(newnode)
            self.length += 1
        else:
            current = self.head.get_ptr()
            while current.get_ptr() != None:
                current = current.get_ptr()
            current.set_ptr(newnode)
            self.length += 1
    def RemoveLast(self):
        if self.isEmpty():
            print("ERROR: UNDERFLOW")
        else:
            previous = self.head
            current = self.head.get_ptr()
            while current.get_ptr() != None:
                current = current.get_ptr()
            previous.set_ptr(None)
            self.length -= 1

    def AddInOrder(self,name,time,freelist):
        F_current = freelist.head.get_ptr()
        F_current.set_name(name)
        F_current.set_time(time)
        
        if self.isEmpty():
            self.head.set_ptr(F_current)
            freelist.head.set_ptr(F_current.get_ptr())
            F_current.set_ptr(None)
            self.length += 1
            
        else:
            R_previous = self.head
            R_current = self.head.get_ptr()
            
            if time < R_current.get_time():
                freelist.head.set_ptr(F_current.get_ptr())
                F_current.set_ptr(self.head.get_ptr())
                self.head.set_ptr(F_current)
                self.length += 1
                
            else:
                while R_current.get_ptr() != None and R_current.get_time() < time:
                    R_previous = R_current
                    R_current = R_current.get_ptr()
                if R_current.get_time() > time:
                    freelist.head.set_ptr(F_current.get_ptr())
                    F_current.set_ptr(R_current)
                    R_previous.set_ptr(F_current)
                    self.length += 1    
                elif R_current.get_ptr() == None:
                    freelist.head.set_ptr(F_current.get_ptr())
                    R_current.set_ptr(F_current)
                    F_current.set_ptr(None)
                    self.length += 1

    def RemoveNode(self,name,freelist):
        if self.isEmpty():
            return "ERROR: Empty list"
        else:
            previous = self.head
            current = self.head.get_ptr()
            while current != None and current.get_name() != name:
                previous = current
                current = current.get_ptr()
            if current.get_name() == name:
                previous.set_ptr(current.get_ptr())
                current.set_ptr(freelist.head.get_ptr())
                freelist.head.set_ptr(current)
            elif current.get_ptr() == None and current.get_name() != name:
                return "ERROR: Unable to find {0}".format(name)
            
def main():
    RaceList = LinkedList()
    FreeList = LinkedList()
    for i in range(20):
        FreeList.AddLast(i)
    print("RaceList")
    print(RaceList.Display())
    print("FreeList")
    print(FreeList.Display())

    more = True
    while more:
        name = input("Enter a name: [XXX to stop] ")
        if name == 'XXX':
            break
        time = input("Enter time: ")
        RaceList.AddInOrder(name,float(time),FreeList)

    print("RaceList")
    print(RaceList.Display())
    print("FreeList")
    print(FreeList.Display())

    more = True
    while more:
        name = input("Enter a name to remove: [XXX to stop] ")
        if name == 'XXX':
            break
        RaceList.RemoveNode(name,FreeList)
        
    print("RaceList")
    print(RaceList.Display())
    print("FreeList")
    print(FreeList.Display())

main()


















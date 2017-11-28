class Node(object):
    def __init__(self):
        self.ptr = None
        self.data = ''

    def get_ptr(self):
        return self.ptr
    def get_data(self):
        return self.data

    def set_ptr(self,newptr):
        self.ptr = newptr
    def set_data(self,newdata):
        self.data = newdata

class Stack_LL_front(Node):
    def __init__(self):
        self.head = Node()
        self.length = 0

    def size(self):
        return self.length

    def __str__ (self):
        text = ''
        current = self.head
        items = self.size()
        while items > 0:
            current = current.get_ptr()
            text += "{0}\n".format(current.get_data())
            items -= 1
        return text

    def isEmpty(self):
        return self.length == 0

    def push(self,item):
        item_node = Node()
        item_node.set_data(item)
        
        if self.isEmpty():
            self.head.set_ptr(item_node)
            self.length += 1
        else:
            item_node.set_ptr(self.head.get_ptr())
            self.head.set_ptr(item_node)
            self.length += 1

    def pop(self):
        if self.isEmpty():
            print("UNDERFLOW")
        else:
            self.head.set_ptr((self.head.get_ptr()).get_ptr())
            self.length -= 1

    def size(self):
        return self.length

class Stack_LL_rear(Node):
    def __init__(self):
        self.head = Node()
        self.length = 0

    def size(self):
        return self.length

    def __str__ (self):
        text = ''
        temp = []
        current = self.head
        items = self.size()
        while items > 0:
            current = current.get_ptr()
            temp.append(current.get_data())
            items -= 1
        for i in range(len(temp)-1,-1,-1):
            text += "{0}\n".format(temp[i])
        return text

    
    def isEmpty(self):
        return self.length == 0

    def push(self,item):
        item_node = Node()
        item_node.set_data(item)
        
        if self.isEmpty():
            self.head.set_ptr(item_node)
            self.length += 1
        else:
            current = self.head
            while current.get_ptr() != None:
                current = current.get_ptr()
            current.set_ptr(item_node)
            self.length += 1

    def pop(self):
        if self.isEmpty():
            print("UNDERFLOW")
        else:
            previous = self.head
            current = self.head
            while current.get_ptr() != None:
                previous = current
                current = current.get_ptr()
            previous.set_ptr(None)
            self.length -= 1

    def size(self):
        return self.length
            
                
            

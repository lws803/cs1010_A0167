## Data structures :: Linked List, Queue, Stack, Binary Tree

#Linked List :: Object Oriented Programming basics
class LL_Node(object):
    def __init__(self,data = '',ptr = None):
        self.data = data
        self.ptr = ptr

    def get_data(self):
        return self.data
    def set_data(self,new):
        self.data = new

    def get_ptr(self):
        return self.ptr
    def set_ptr(self,new):
        self.ptr = new

class LinkedList(object):
    def __init__(self):
        self.length = 0
        self.head = LL_Node()

    def isEmpty(self):
        return self.length == 0

    def display(self):
        text = ''
        current = self.head.get_ptr()
        while current != None:
            text += "{0}\n".format(current.get_data())
            current = current.get_ptr()
        return text

    def addNode(self,data):
        newnode = LL_Node(data)
        if self.isEmpty():
            self.head.set_ptr(newnode)
            self.length += 1
        else:
            current = self.head.get_ptr()
            previous = self.head
            if current.get_data() > data:
                newnode.set_ptr(self.head.get_ptr())
                self.head.set_ptr(newnode)
                self.length += 1
            else:
                while current.get_ptr() != None and current.get_data() < data:
                    previous = current
                    current = current.get_ptr()
                if current.get_data() > data and current.get_ptr() != None:
                    newnode.set_ptr(current)
                    previous.set_ptr(newnode)
                    self.length += 1
                else:
                    current.set_ptr(newnode)
                    self.length += 1

    def delNode(self,data):
        if self.isEmpty():
            print("ERROR: Underflow.")
            return
        else:
            previous = self.head
            current = self.head.get_ptr()
            while current.get_data() != data and current.get_ptr() != None:
                previous = current
                current = current.get_ptr()
            if current.get_data() == data:
                previous.set_ptr(current.get_ptr())
                self.length -= 1
            else:
                print("ERROR: Unable to find data to remove.")

    def search(self,data):
        if self.isEmpty():
            print("ERROR: No data to find.")
            return False
        else:
            previous = self.head
            current = self.head.get_ptr()
            while current.get_data() != data and current.get_ptr() != None:
                previous = current
                current = current.get_ptr()
            if current.get_data() == data:
                return True
            else:
                print("ERROR: Unable to find data.")
                return False

# Queue :: Handling using array in a class
class CircularQueue(object):
    def __init__(self):
        self.length = 0
        self.data = []
        self.start = 0
        self.front = 0
        self.rear = 0

    def display(self):
        return self.data

    def Create(self,number):
        self.data = []
        self.max = number - 1
        for i in range(number):
            self.data.append("")

    def additem(self,new):
        if self.length == self.max:
            print("ERROR: No space left.")
        else:
            if self.rear == self.max:
                self.rear = 0
            else:
                self.rear += 1
                self.data[self.rear] = new
                self.length += 1

    def delitem(self):
        if self.length == 0:
            print("ERROR: Underflow.")
        else:
            deleted_item = self.data[self.front]
            self.length -= 1
            if self.front == self.rear:
                self.front = 0
            else:
                self.front += 1

# Queue :: Handling using Linked List
class Queue(object):
    def  __init__(self):
        self.length = 0
        self.head = LL_Node()

    def display(self):
        text = ''
        current = self.head.get_ptr()
        while current != None:
            text += "{0}\n".format(current.get_data())
            current = current.get_ptr()
        return text

    def additem(self,new):
        newnode = LL_Node(new)
        if self.length == 0:
            self.head.set_ptr(newnode)
            self.length += 1
        else:
            newnode.set_ptr(self.head.get_ptr())
            self.head.set_ptr(newnode)
            self.length += 1

    def delitem(self):
        if self.length == 0:
            print("ERROR: Underflow.")
        else:
            current = self.head.get_ptr()
            previous = self.head
            while current.get_ptr() != None:
                previous = current
                current = current.get_ptr()
            previous.set_ptr(None)
            self.length -= 1
            return current.get_data()

# Stack :: Handling using array in class
class stack(object):
    def __init__(self):
        self.length = 0
        self.data = []
        
    def display(self):
        return self.data
    def additem(self,item):
        self.data.append(item)

    def delitem(self):
        return self.data.pop(self.length - 1)
    
    def peek(self):
        return self.data[self.length -1]

class OPstack(object):
    def __init__(self):
        self.length = 0
        self.head = LL_Node()

    def display(self):
        text = ''
        current = self.head.get_ptr()
        while current != None:
            text += "{0}\n".format(current.get_data())
            current = current.get_ptr()
        return text

    def additem(self,new):
        newnode = LL_Node(new)
        if self.length == 0:
            self.head.set_ptr(newnode)
            self.length += 1
        else:
            newnode.set_ptr(self.head.get_ptr())
            self.head.set_ptr(newnode)
            self.length += 1

    def delitem(self):
        if self.length == 0:
            print("ERROR: Underflow.")
        else:
            current = self.head.get_ptr()
            self.head.set_ptr(current.get_ptr())
            self.length -= 1
            return current.get_data()

# BinaryTree :: class implementation
class BT_BT_Node(object):
    def __init__(self,left = None, data = '',right = None):
        self.left = left
        self.right = right
        self.data = data

    def get_left(self):
        return self.left
    def set_left(self,new):
        self.left = new

    def get_right(self):
        return self.right
    def set_right(self,new):
        self.right = new

    def get_data(self):
        return self.data
    def set_data(self,new):
        self.data = new

class BinaryTree(object):
    def __init__(self):
        self.root = BT_Node()
        self.length = 0

    def isEmpty(self):
        return self.length == 0
    
    def additem(self,data):
        newBT_Node = BT_Node(None,data,None)
        if self.isEmpty():
            self.root = newBT_Node
            self.length += 1
        else:
            previous = self.root
            current = self.root
            last = 'X'
            while current != None:
                if data > current.get_data():
                    last = 'R'
                    previous = current
                    current = current.get_right()
                elif data <= current.get_data():
                    last = 'L'
                    previous = current
                    current = current.get_left()
            if last == 'R':
                previous.set_right(newBT_Node)
                self.length += 1
            elif last == 'L':
                previous.set_left(newBT_Node)
                self.length += 1

def inorder(tree,current = ''):
    if current == '':
        current = tree.root
    if current != None:
        inorder(tree,current.get_left())
        print(current.get_data())
        inorder(tree,current.get_right())

def preorder(tree,current = ''):
    if current == '':
        current = tree.root
    if current != None:
        print(current.get_data())
        inorder(tree,current.get_left())
        inorder(tree,current.get_right())

def postorder(tree,current = ''):
    if current == '':
        current = tree.root
    if current != None:
        inorder(tree,current.get_left())
        inorder(tree,current.get_right())
        print(current.get_data())
       
# Denary to anything :: convert denary to any base representation
def dec2any(denary,base):
    subs = '0123456789ABCDEF'
    text = ''
    while denary > 0:
        remainder = denary % base       #obtain the remainder
        denary = denary // base         #get the next value
        text = subs[remainder] + text
    return text

# Anything to denary :: convert representation to denary
def any2dec(rep,base):
    subs = '0123456789ABCDEF'
    reverse = rep[::-1]
    denary = 0
    for i in range(len(reverse)):
        denary += subs.index(reverse[i].upper()) * (base**i)
    return denary
























    

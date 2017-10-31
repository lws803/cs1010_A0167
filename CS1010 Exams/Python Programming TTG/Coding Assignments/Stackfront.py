class Stack_front(object):
    def __init__(self):
        self.array = []
        
    def __str__(self):
        text = ''
        for i in self.array:
            text += "|{0:^10}|\n".format(i)
        return text
    
    def isEmpty(self):
        if len(self.array) == 0:
            return True
        else:
            return False
        
    def push(self,item):
        self.array.insert(0,item)
        
    def pop(self):
        if self.isEmpty():
            print("UNDERFLOW")
        else:
            self.array.pop(0)
        
    def size(self):
        return len(self.array)


class Stack_rear(object):
    def __init__(self):
        self.array = []
        
    def __str__(self):
        text = ''
        for i in range(len(self.array) - 1, -1,-1):
            text += "{0}\n".format(self.array[i])
        return text
    
    def isEmpty(self):
        if len(self.array) == 0:
            return True
        else:
            return False
        
    def push(self,item):
        self.array.insert(len(self.array),item)
        
    def pop(self):
        if self.isEmpty():
            print("UNDERFLOW")
            return
        else:
            self.array.pop(len(self.array)-1)
        
    def size(self):
        return len(self.array)

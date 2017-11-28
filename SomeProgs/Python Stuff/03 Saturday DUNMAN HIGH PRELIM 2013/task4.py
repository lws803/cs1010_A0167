class Node(object):
    def __init__(self,name = '',score = 0,ptr = None):
        self.name = str(name)
        self.score = int(score)
        self.ptr = ptr

    def get_name(self):
        return self.name
    def set_name(self,new):
        self.name = new

    def get_score(self):
        return self.score
    def set_score(self,new):
        self.score = new

    def get_ptr(self):
        return self.ptr
    def set_ptr(self,new):
        self.ptr = new

class LinkedList(object):
    def __init__(self):
        self.head = Node()
        self.length = 0

    def empty(self):
        return self.length == 0

    def additem(self,name = '',score = 0):
        newdata = Node(name,score)
        if self.empty():
            self.head.set_ptr(newdata)
            self.length += 1
        else:
            previous = self.head
            current = self.head.get_ptr()
            if score > current.get_score():
                newdata.set_ptr(self.head.get_ptr())
                self.head.set_ptr(newdata)
                self.length += 1
            else:
                while current.get_ptr() != None and current.get_score() > score:
                    previous = current
                    current = current.get_ptr()
                if current.get_score() == score:
                    if name < current.get_name():
                        newdata.set_ptr(current)
                        previous.set_ptr(newdata)
                        self.length += 1
                    else:
                        maintain_score = score
                        while current.get_ptr() != None and current.get_name() < name and current.get_score() == maintain_score:
                            previous = current
                            current = current.get_ptr()
                        if current.get_ptr() == None:
                            current.set_ptr(newdata)
                            self.length += 1
                        elif current.get_score() != maintain_score and current.get_ptr() != None:
                            newdata.set_ptr(current)
                            previous.set_ptr(newdata)
                            self.length += 1
                        elif current.get_name() > name:
                            newdata.set_ptr(current)
                            previous.set_ptr(newdata)
                            self.length += 1
                elif current.get_ptr() == None:
                    current.set_ptr(newdata)
                    self.length += 1
                elif current.get_score < score:
                    newdata.set_ptr(current)
                    previous.set_ptr(newdata)
                    self.length += 1

    def display(self):
        text = ''
        current = self.head.get_ptr()
        while current.get_ptr() != None:
            temp = '{0},{1}\n'.format(current.get_name(),current.get_score())
            text += temp
            current = current.get_ptr()

        temp = '{0},{1}'.format(current.get_name(),current.get_score())
        text += temp
        print(text)

                    
                        
                            
                            
                













                

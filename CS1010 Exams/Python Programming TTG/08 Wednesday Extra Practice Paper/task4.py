class Node(object):
    def __init__(self,score='',name='',left=None,right=None):
        self.score = score
        self.name = name
        self.left = left
        self.right = right

    def get_score(self):
        return self.score
    def set_score(self,new):
        self.score = new

    def get_name(self):
        return self.name
    def set_name(self,new):
        self.name = new

    def get_left(self):
        return self.left
    def set_left(self,new):
        self.left = new

    def get_right(self):
        return self.right
    def set_right(self,new):
        self.right = new

class BinaryTree(object):
    def __init__(self):
        self.length = 0
        self.root = Node()

    def isEmpty(self):
        return self.length == 0

    def additem(self,score,name):
        newnode = Node(score,name,None,None)
        if self.isEmpty():
            self.root = newnode
            self.length += 1
        else:
            previous = self.root
            current = self.root
            last = 'X'
            while current != None:
                if score <= current.get_score():
                    previous = current
                    current = current.get_left()
                    last = 'l'
                elif score > current.get_score():
                    previous = current
                    current = current.get_right()
                    last = 'r'
            if last == 'l':
                previous.set_left(newnode)
                self.length += 1
            else:
                previous.set_right(newnode)
                self.length += 1
                
    def searchName(self,score):
        people = []
        if self.isEmpty():
            return "No items"
        else:
            current = self.root
            while current != None:
                if score < current.get_score():
                    current= current.get_left()
                elif score > current.get_score():
                    current = current.get_right()
                elif score == current.get_score():
                    people.append(current.get_name())
                    current = current.get_left()
            return people
            

def RankList(tree,current = ''):
    if current == '':
        current = tree.root
    
    if current != None:
        RankList(tree,current.get_right())
        print(current.get_name(),current.get_score())
        RankList(tree,current.get_left())

def GetLowest(tree):
##    available = []
##    for i in range(0,101):
##        available.append(i)
##    possiblescore = []
##    for j in available:
##        if len(tree.searchName(j)) != 0:
##            possiblescore.append(j)
##            
##    lowest = 101
##    for k in possiblescore:
##        if k < lowest:
##            lowest = k
##            print(lowest)
##    print(possiblescore)
##    print(lowest)
    current = tree.root
    while current.get_left() != None:
        current = current.get_left()
    return current.get_score()

def SearchMoreEqual(tree,score):
    available = []
    for i in range(score,101):
        available.append(i)
##    print(available)
    search_results = []
    for i in available:
        search_results += tree.searchName(i)
    return list(search_results)

def ConstructBST():
    tree = BinaryTree()
    infile = open("EXAM.txt","r")
    data = infile.readlines()
    for i in data:
        name,score = i.split(',')
        tree.additem(int(score),name)
    print("Name","score")
    RankList(tree,'')
    print(GetLowest(tree))
    print(SearchMoreEqual(tree,70))

ConstructBST()



    





                

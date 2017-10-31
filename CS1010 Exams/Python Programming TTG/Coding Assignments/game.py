class Node(object):
    def __init__ (self, player = '',score = 0 ,ptr = None,rank = 0):
        self.player = player
        self.score = score
        self.ptr = ptr
        self.rank = rank

    def set_player(self,player):
        self.player = player

    def get_player(self):
        return self.player

    def set_score(self,score):
        self.score = score

    def get_score(self):
        return self.score
    
    def set_ptr(self,ptr):
        self.ptr = ptr

    def get_ptr(self):
        return self.ptr

    def set_rank(self,rank):
        self.rank = rank

    def get_rank(self):
        return self.rank

    def __str__(self):
        text = '{0},{1}'.format(self.player,self.score)
        return text
    
class LinkedList(object):
    def __init__ (self):
        self.length = 0
        self.head = Node()

    def sortNames(self,player,current,previous):
        if player.get_player() > current.get_player():
            previous.set_ptr(player)
            player.set_ptr(current)
            self.length += 1
            return
        else:
            while player.get_player() < current.get_player() and current.get_score() == player.get_score() and current.get_ptr() != None:
                previous = current
                current = current.get_ptr()
            if player.get_player() < current.get_player() and current.get_score() != player.get_score():
                player.set_ptr(current.get_ptr())
                current.set_ptr(player)
                self.length += 1
            else:
                previous.set_ptr(player)
                player.set_ptr(current)
                self.length += 1

    def insertPlayer(self,player):
        if self.length == 0:
            self.head.set_ptr(player)
            self.length += 1
        else:
            current = self.head.get_ptr()
            if player.get_score() > current.get_score():
                player.set_ptr(current)
                self.head.set_ptr(player)
                self.length += 1

            elif player.get_score() == current.get_score():
                self.sortNames(player,current,self.head)
                return
            else:
                previous = self.head
                while player.get_score() <= current.get_score() and current.get_ptr() != None:
                    previous = current
                    current = current.get_ptr()

                if player.get_score() == current.get_score():
                    self.sortNames(player,current,previous)
                    return
                    
                if player.get_score() < current.get_score() and current.get_ptr() == None:
                    current.set_ptr(player)
                    self.length += 1
                else:
                    player.set_ptr(current)
                    previous.set_ptr(player)
                    self.length += 1
                    

    def removePlayer(self,name):
        current = self.head.get_ptr()
        previous = self.head
        while current.get_ptr() != None and current.get_player() != name:
            previous = current
            current = current.get_ptr()
        if current.get_player() == name:
            previous.set_ptr(current.get_ptr())

    def searchPlayer(self,name):
        current = self.head.get_ptr()
        previous = self.head
        while current.get_ptr() != None and current.get_player() != name:
            previous = current
            current = current.get_ptr()
        if current.get_player() == name:
            return current
        else:
            return None

    def rankEverybody(self):
        currentPosition = 1
        rankNo = 1
        length = self.length
        current = self.head
        previous = self.head
        
        while length > 0:
            previous = current
            current = current.get_ptr()
            if current.get_score() == previous.get_score():
                current.set_rank(rankNo)
            else:
                current.set_rank(currentPosition)
                rankNo = currentPosition
            currentPosition += 1
            length -= 1
            
    def display(self):
        text = ''
        current = self.head.get_ptr()
        text += "{0:^15}:{1:^15}:{2:^15}\n".format("Rank","PlayerName","PlayerScore")
        while current.get_ptr() != None:
            newline = "{0:^15}:{1:^15}:{2:^15}\n".format(current.get_rank(),current.get_player(),current.get_score())
            text += newline
            current = current.get_ptr()
        text += "{0:^15}:{1:^15}:{2:^15}\n".format(current.get_rank(),current.get_player(),current.get_score())
        
        return text

def validate_name(name):
    if name[0].isalpha() and len(name) >= 3:
        return False
    else:
        print("WARNING: Names begin with letters and longer than 3 letters")
        return True

def validate_score(score):
    if score < 0 or score > 20 or type(score) != int:
        print("WARNING: Score between 0 and 20.")
        return True
    else:
        return False

def More(result):
    if result == 'Y' or result == 'y':
        return False
    elif result == 'N' or result == 'n':
        return False
    else:
        print("Enter a valid response!")
        return True

def main():
    infile = open("GAME.dat","r")
    data = infile.readlines()
    playerList = LinkedList()
    for i in data:
        tempdata = i.split(' ')
        player = Node(tempdata[0],int(tempdata[1][:-1]),None)
        playerList.insertPlayer(player)
##    playerList.rankEverybody()
    
##    print(playerList.length)
##    print(playerList.display())
    
    moreChanges = True
    while moreChanges:
        print("Pick an option:")
        print("1. Input new player score or update player score.")
        print("2. Search for a player's score.")
        print("3. Display the player database.")
        print("4. Exit the program.")
        
        choice = ''
        choice  = input("Enter a choice: ")
        if choice == '1':
            invalidName = True
            while invalidName:
                playerName = input("Enter player name: ")
                invalidName = validate_name(playerName)
                
            invalidScore = True
            while invalidScore:
                score = eval(input("Enter Score: "))
                invalidScore = validate_score(score)

            playerNode = playerList.searchPlayer(playerName)
            if playerNode == None:
                playerNode = Node(playerName,0,None)
            else:
                playerList.removePlayer(playerName)
            
            playerNode.set_score(playerNode.get_score() + score)
            playerList.insertPlayer(playerNode)
##            playerList.rankEverybody()
            print("{0}".format(playerList.display()))

        elif choice == '2':
            searching = input("Enter players name to search: ")
            searched = playerList.searchPlayer(searching)
            if searched != None:
                print(searched)
            else:
                print("{0} is not found in player database.\n".format(searching))

        elif choice == '3':
            print(playerList.display())

        elif choice == '4':
            moreChanges = False

        else:
            print("WARNING: Enter a valid option.\n")
        
main()
        












        

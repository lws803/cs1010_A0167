# Name: Tan Tze Guang
# Class: 13S28
# Date: 29 April 2013
# program: HIGHEST.py
# This program compares the day's scores to get the highest score
# Then it compares the highest score so far to the best of the day
# overwrites the highest score if defeated

def highest(compare):
    if compare[0][1] > compare[1][1]:
        print("highscore was not beaten by todays players")
        # does not overwrite score in highest.txt

    else:
        print("Highscore was beaten by todays highscore!")
        outfile = open("HIGHEST.txt",'w') # overwrite score
        print(compare[1][0],file = outfile)
        print(compare[1][1],file = outfile)
        outfile.close()

def display(data,player,bestPlayer,compare): #displays the days score
    print("{0:^20}{1:^5}".format("Name","Score"))
    for i in range(len(data)):
        for j in range(len(player)):
            if j == 0:
                print("{0:^20}".format(data[i][j]),end = "")
            elif j == 1:
                print("{0:^5}".format(data[i][j]))

    print()
    print("The best player is \"",bestPlayer[0],"\" with a score of",bestPlayer[1])
    highest(compare)
    
def anymore(choice): # check for more input
    if choice[0] == "Y" or choice[0] == "y":
        return True
    else:
        return False

def validateScore(score): # checks score whether it is within range
    if score <= 500 and score >= 1:
        return False
    else:
        print("Invalid Score... range (1 to 500)")
        return True
    
def todayInput(data):
    #program ask for up to 5 input
    more = True
    noInput = 1
    highToday = 0
    playerHigh = ""
    BestPlayer = []
    while more and noInput <= 5:
        player = [] # create list to store player info
        username = input("Enter name of player: ")
        invalidScore = True
        while invalidScore: # ensures score between acceptable range
            score = eval(input("Enter Score of player: (1 to 500) "))
            invalidScore = validateScore(score)
        if score > highToday: # looks for the day's highscore
            highToday = score
            playerHigh = username
        
        player.append(username)
        player.append(score)

        data.append(player)
        noInput = noInput + 1

        if noInput < 6:
            choice = input("Anymore entries? (Y/N)")
            more = anymore(choice)
            print()

    BestPlayer.append(playerHigh)
    BestPlayer.append(highToday)
    return data,BestPlayer,player
                
def main():
    print("This program compares the day's scores to get the highest score.")
    print("Then it compares the highest score so far to the best of the day.")
    print("overwrites the highest score if defeated")
    print()
    infile = open("HIGHEST.txt",'r')
    highest_user = infile.readline()
    highest_user = highest_user[:-1] # removes the newline character
    highest_score = infile.readline()
    highest_score = int(highest_score)
    best = [highest_user,highest_score] # stores the best score thus far for comparison
    infile.close()

    print("Best player thus far:",best[0])
    print("Best score:",best[1])

    data = []
    data, todayBest,players = todayInput(data)
    compare = [best,todayBest]
    display(data,players,todayBest,compare)
    
main()

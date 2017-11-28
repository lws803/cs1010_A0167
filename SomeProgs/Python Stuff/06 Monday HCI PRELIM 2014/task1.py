def main():
    infile = open("HIGHEST.txt","r")
    data = infile.readline()
    current_name,current_highscore = data.split(',')

    new_highest = ''
    new_highscore = 0
    more = True
    while more:
        name = input("Enter player name: ")
        valid = False
        while not valid:
            score = eval(input("Enter player score: "))
            if score <= 500 and score > 0:
                valid = True
        
        if score > int(new_highscore):
            new_highscore = score
            new_highest = name
        response = input("Anymore? [y/n] ")
        if response[0].upper() == 'N':
            more = False
        else:
            more = True

    print("Player {0} got a highscore of {1} for today.".format(new_highest,new_highscore))
    
    if new_highscore > int(current_highscore):
        print("Player {0} got a new all time highscore of {1}.".format(new_highest,new_highscore))
        print("Beating current highscore of {0} by {1}".format(int(current_highscore),current_name))
        outfile = open("HIGHEST.txt",'w')
        print(new_highest+','+str(new_highscore),file = outfile)
        outfile.close()

##main()

def check_palindrome():
    low = eval(input("Enter lower end: "))
    high = eval(input("Enter higher end: "))
    palindrome = []
    for number in range(low,high+1,1):
        string_number = str(number)
        reverse = ''
        for letter in string_number:
            reverse = letter + reverse
        if reverse == string_number:
            palindrome.append(number)

    for i in palindrome:
        print(i)

check_palindrome()









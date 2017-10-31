def main():
    infile = open("HIGHEST.txt","r")
    data = infile.readline()
    current_name,current_score = data.split(' ')
    highest_score = 0
    highest_name = ''
    infile.close()

    more = True
    count = 5
    while more and count > 0:
        name = input("Enter player name: ")
        valid = False
        while not valid:
            score = eval(input("Enter player score: [1-500] "))
            if score > 500 or score <= 0:
                valid = False
            else:
                valid = True

        if score > highest_score:
            highest_score = score
            highest_name = name
        count -= 1

    print("{0} is todays top scorer with a score of {1}".format(highest_name,highest_score))
    if highest_score > int(current_score):
        print("{0} gets the new all time highscore.".format(highest_name))
        print("Winning {0} of {1}".format(current_name,current_score))

        outfile = open("HIGHEST.txt","w")
        print(str(highest_name)+' '+str(highest_score),file = outfile)
        outfile.close()
    

main()

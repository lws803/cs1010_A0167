def main():
    infile = open("RESULTS.txt","r")
    data = infile.readlines()
    dictionary = {}
    for i in data:
        team_name, current_average_rank = i.split(' ')
        dictionary[team_name] = float(current_average_rank)
    team_data = []
    count = 5
    more = True
    rank = [1,2,3,4,5]
    while more and count > 0:
        teamName = input("Enter team name: ")
        valid = False
        while not valid:
            teamRank = eval(input("Enter the rank for the last day: "))
            if teamRank in rank:
                rank.remove(teamRank)
                valid= True
        team_data.append([teamName,teamRank])
        response = input("Anymore data: [y/n] ")
        count -= 1
        if count > 0:
            if response[0].upper() == 'Y':
                more = True
            else:
                more = False
    highest = 999
    highest_team = ''
    for i in team_data:
        dictionary[i[0]] = (dictionary[i[0]]*4 + float(i[1])) / 5
        if dictionary[i[0]] < highest:
            highest = dictionary[i[0]]
            highest_team = i[0]

    print(dictionary)
    print(highest)
    print(highest_team)

    outfile = open("RESULTS.txt","w")
    for i in dictionary.keys():
        print(i, '{0:.2f}'.format(dictionary[i]),file = outfile)

    infile.close()
    outfile.close()
main()
        

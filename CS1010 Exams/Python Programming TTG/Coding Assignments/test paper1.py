def main():
    infile = open("WORDS2.txt","r")
    data = infile.readlines()
    infile.close()
    
    templist = []
    wordlist = []
    numberlist = []

    for i in data:
        templist.append(i[:-1])
    
    for i in templist:
        if i.isnumeric():
            numberlist.append(int(i))
        else:
            wordlist.append(i)
            
    highest = 0
    freqlist = []
    for i in numberlist:
        if i > highest:
            highest = i

    for i in range(len(numberlist)):
        if numberlist[i] == highest:
            freqlist.append(wordlist[i])

    print(freqlist)
main()

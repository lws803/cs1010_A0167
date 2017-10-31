def main():
    infile = open("WORDS2.txt","r")
    data = infile.readlines()
    occur = []
    terms = []
    for i in range(len(data)):
        if i % 2 == 0:
            terms.append(data[i][:-1])
        else:
            occur.append(int(data[i][:-1]))
    print(occur)
    print(terms)

    highest = 0
    highest_term = []
    for i in range(len(occur)):
        if occur[i] == highest:
            highest_term.append(terms[i])
        if occur[i] > highest:
            highest = occur[i]
            highest_term = [terms[i]]
    print(highest_term,highest)

main()
            

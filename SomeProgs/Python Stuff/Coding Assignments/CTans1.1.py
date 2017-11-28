def main():
    infile = open("WORDS2.txt","r")

    num = 0
    highest = 0
    highest_terms = []

    for line in infile.readlines():
        if num%2 == 0:
            term = line.rstrip()
        else:
            frequency = int(line.rstrip())
            if frequency > highest:
                highest = frequency
                highest_terms = []
                highest_terms.append(term)
            elif frequency == highest:
                highest_terms.append(term)
        num += 1

    print("Highest number of occurances",highest,"is",highest_terms)

main()

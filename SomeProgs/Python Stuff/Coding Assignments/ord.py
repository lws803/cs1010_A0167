def main():
    infile = open("words.txt",'r')
    data = infile.read()
    data = data.split(", ")
    infile.close()
    word_dict = {}
    for i in data:
        sums = 0
        for j in i:
            sums = sums + ord(j)
            word_dict[i] = sums
    
    print("Cordial" in word_dict)
    print("Helper" in word_dict)
    print("Courage" in word_dict)

main()

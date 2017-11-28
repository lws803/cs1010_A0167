# Name: Tan Tze Guang
# Class: 13S28
# Date: 11 March 2013
# This program batch grades to the corresponding batch score

def main():
    print("This program batch grades to the corresponding batch score.")
    grades = ['F','E','D','C','B','A']

    infile = open("score.txt","r")
    outfile = open("grade.txt","w")

    for score in infile:
        grade = grades[int(score)]
        print(grade, file = outfile)

    print("Output has been saved in \"grade\"")

main()

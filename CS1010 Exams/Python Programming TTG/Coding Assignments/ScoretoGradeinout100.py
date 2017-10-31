# Name: Tan Tze Guang
# Class: 13S28
# Date: 11 March 2013
# This program batch grades to the corresponding batch score

def main():
    print("This program batch grades to the corresponding batch score.")
    grades = ['F','F','F','F','F','E','D','C','B','A']

    infile = open("exam.txt","r")
    outfile = open("grade.dat","w")

    for score in infile.readlines():
        grade = grades[(int(score)// 10)-1]
        print(grade, file = outfile)

    print("Output has been saved in \"grade\"")

    infile.close()
    outfile.close()
    
main()

# Name: Tan Tze Guang
# Class: 13S28
# Date: 7 March 2013
# This program gives a grade to the corresponding mark

def main():
    print("This program gives a grade to the corresponding mark.")
    grades = ['F','E','D','C','B','A']
    score = eval(input("Input your mark: "))

    print("Your grade is:", grades[score])

main()

# Name: Tan Tze Guang
# Class: 13S28
# Date: 14 March 2013
# This program grades a 5 point quiz

def grade(score):
    grades = ('F','E','D','C','B','A')
    return grades[score]

def main():
    print("This is a program which grades a 5 point quiz.")
    score = eval(input("Input your score: "))

    if score < 6 and score >= 0:
        new_grade = grade(score)
        print("Your grade is: {0}".format(new_grade))
        
    else:
        print("This is an invalid input.")

main()

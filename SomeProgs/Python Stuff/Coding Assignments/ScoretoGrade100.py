# Name: Tan Tze Guang
# Class: 13S28
# Date: 7 March 2013
# This program shows the grade to the corresponding score

def main():
    print("This program shows the grade to the corresponding score")
    grade = ['F','F','F','F','F','E','D','C','B','A']
    score = eval(input("Input your score (0-100): "))

    score = score // 10

    print("Your Grade is: ",grade[score])

main()
    

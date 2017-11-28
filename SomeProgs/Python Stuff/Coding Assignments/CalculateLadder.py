#File: CalculateLadder
#This is a program to calculate the length of ladder needed to reach a given height

import math
def main():
    height,angle = eval(input("Enter the required fields (Height,Angle): "))

    length = height / math.sin(angle)

    print("The length of the ladder should be: ",length)

main()

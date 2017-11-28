# File: CalculateDist.py
# This is a program to calculate the distance between 2 points

import math
def main():
    x1,y1 = eval(input("Enter coordinates of first point(x,y): "))
    x2,y2 = eval(input("Enter coordinates of second point(x,y): "))
    distance = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)
    print("The distance between the 2 points is: ",distance)

main()

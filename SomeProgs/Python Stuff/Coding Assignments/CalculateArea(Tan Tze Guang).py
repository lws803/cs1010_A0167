# Name: Tan Tze Guang
# File: CalculateArea.py
# This is a program to calculate the area of a triangle.

import math
def main():
    print("This program calculates the area of the triangle from the length of 3 sides")
    a,b,c = eval(input("Enter the 3 lengths of the triangle (a,b,c): "))

    s = (a+b+c)/2
    temp_area = (s)*(s-a)*(s-b)*(s-c)
    area = math.sqrt(temp_area)
    
    print("The area of the triangle is: ",area)

main()

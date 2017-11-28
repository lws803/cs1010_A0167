# CalculateSlope.py
# This is a program to calculate the slope of a line through 2 points

def main():
    x1, y1 = eval(input("Please enter the coordinates of the first point(x,y): "))
    x2, y2 = eval(input("Please enter the coordinates of the second point(x,y): "))
    slope = (y2 - y1)/(x2 - x1)
    print("The slope of the line is : ",slope)

main()

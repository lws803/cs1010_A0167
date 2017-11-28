# Name: Tan Tze Guang
# Class: 13S28
# Date: 28 March 2013
# This programs determines whether a triangle can be formed with three sticks.

def is_triangle(length_a, length_b, length_c):
    if length_a > length_b + length_c:
        print("No")
    elif length_b > length_a + length_c:
        print("No")
    elif length_c > length_b + length_a:
        print("No")
    else:
        print("Yes")

def main():
    print("This program determines whether a triangle can be formed with 3 sticks")

    length_1 = eval(input("What is the length of the first stick: "))
    length_2 = eval(input("What is the length of the second stick: "))
    length_3 = eval(input("What is the lenght of the third stick: "))

    is_triangle(length_1, length_2, length_3)

main()

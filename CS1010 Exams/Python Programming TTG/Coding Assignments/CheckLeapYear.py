# Name: Tan Tze Guang
# Class: 13S28
# Date: 28 March 2013
# This program determines whether the year is a leap year

def main():
    year = eval(input("What year is this: "))
    check_century = year % 100

    if check_century == 0:
        print("This is a century year.")
        check_leap = year % 400

        if check_leap == 0:
            print("This is a leap year")
        else:
            print("This is not a leap year")

    else:
        check_leap = year % 4

        if check_leap == 0:
            print("This is a leap year")
        else:
            print("This is not a leap year")

main()

# Name: Tan Tze Guang
# Class: 13S28
# Date: 28 March 2013
# This program calculates the total wages in one week with
# over time if work hours is more than 40

def main():
    work_hours = eval(input("How many hours did you work this week: "))
    if work_hours > 40:
        work_hours = work_hours * 1.5

    work_rate = eval(input("Whats your salary per hour: "))

    totalWage = work_rate * work_hours

    print("Your total wage this week is:",totalWage)

main()

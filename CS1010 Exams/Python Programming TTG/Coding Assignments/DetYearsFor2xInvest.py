# Name: Tan Tze Guang
# Class: 13S28
# Date: 1 April 2013
# This program determines the time taken to double the investment

def main():
    print("This program determines the time taken to double the investment")
    print()
    investment = eval(input("Enter the amount of investment: "))
    int_rate = eval(input("Enter the annual interest rate(in percentage): "))
    int_rate = 1 + int_rate/100
    
    initial_investment = investment
    years = 0

    while investment < 2*initial_investment:
        investment = investment * int_rate
        years += 1

    print("It takes",years,"years to get 2 times of your initial investment")

main()

# Name: Tan Tze Guang
# Class: 13S28
# Date: 1 April 2013
# This program determines:
# a) weeks needed to get rats to 125% weight from original weight.
# b) no. of weeks for rat1 to be 10% heavier than rat2.

def part_a():
    rat_1_weight = eval(input("Enter weight of the 1st rat(in grams): "))
    initial_weight = rat_1_weight

    rat_1_rate = eval(input("Enter the expected rate of increase in weight each week(in percentages): "))
    rat_1_rate = 1 + rat_1_rate / 100
    
    weeks = 0
    
    while rat_1_weight < 1.25*initial_weight:
        rat_1_weight = rat_1_weight * rat_1_rate
        weeks += 1

    print("It takes",weeks,"weeks to get the rat to increase to 125% of original weight")
    
def part_b():
    print("Assuming the 2 rats have the same weight.")
    rat_1_weight = eval(input("Input the weight of the rats: "))
    rat_2_weight = rat_1_weight

    print("Rat 1 is expected to gain weight faster than rat 2")
    rat_1_rate = eval(input("Input the rate of increase in weight for rat 1(in percentage): "))
    rat_1_rate = 1 + rat_1_rate / 100
    rat_2_rate = eval(input("Input the rate of increase in weight for rat 2(in percentage): "))
    rat_2_rate = 1 + rat_2_rate / 100
    
    if rat_1_rate > rat_2_rate:
        weeks = 0
        while rat_1_weight < 1.1*rat_2_weight:
            rat_1_weight = rat_1_weight * rat_1_rate
            rat_2_weight = rat_2_weight * rat_2_rate
            weeks += 1
        print("It takes",weeks,"weeks for rat 1 to be 10% heavier than rat 2")

    elif rat_2_rate >= rat_1_rate:
        print("Rat 1 is supposed to gain more weight than rat 2 every week")

def main():
    print("This program determines:")
    print("a) weeks needed to get rats to 125% weight from original weight.")
    part_a()
    print()
    print("b) no. of weeks for rat1 to be 10% heavier than rat2.")
    part_b()

main()

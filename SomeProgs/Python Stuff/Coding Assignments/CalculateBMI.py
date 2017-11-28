# Name: Tan Tze Guang
# Class: 13S28
# Date: 28 March 2013
# This program determines a person's BMI and determines
# whether they are healthy or not

def main():
    weight = eval(input("What is your weight in Kilograms: "))
    height = eval(input("what is your height in Metres: "))

    BMI = weight / height**2

    if BMI >= 20 and BMI <= 25:
        print("You are healthy!")

    else:
        print("You are unhealthy...")

main()

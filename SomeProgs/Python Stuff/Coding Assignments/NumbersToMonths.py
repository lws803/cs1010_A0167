# This is a progam to print the month to the corresponding number

def main():
    months = "JanFebMarAprMayJunJulAugSepOctNovDec"
    print("This program prints the month corresponding to the number input")
    
    month_n = eval(input("Input the month in \"mm\" format: "))

    if month_n == 1:
        print("This number corresponds to: " + months[0:3])
    elif month_n == 2:
        print("This number corresponds to: " + months[3:6])
    elif month_n == 3:
        print("This number corresponds to: " + months[6:9])
    elif month_n == 4:
        print("This number corresponds to: " + months[9:12])
    elif month_n == 5:
        print("This number corresponds to: " + months[12:15])
    elif month_n == 6:
        print("This number corresponds to: " + months[15:18])
    elif month_n == 7:
        print("This number corresponds to: " + months[18:21])
    elif month_n == 8:
        print("This number corresponds to: " + months[21:24])
    elif month_n == 9:
        print("This number corresponds to: " + months[24:27])
    elif month_n == 10:
        print("This number corresponds to: " + months[27:30])
    elif month_n == 11:
        print("This number corresponds to: " + months[30:33])
    elif month_n == 12:
        print("This number corresponds to: " + months[33:36])
    else:
        print("This is an invalid input...")

main()

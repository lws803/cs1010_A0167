def main():
    number = eval(input("Input a number: "))
    number = str(number)
    digits = number.split()
    digits = digits.reverse()

    print("The reversed number is: ",digits)

main()

#File: Convert celsius to farenheit
#
def main():
    print("This is a program to cenvert celsius temp to farenheit temp")
    celsius = eval(input("What is the temparature in celsius?: "))
    farenheit = celsius*9/5 + 32
    print("The temperature is,",farenheit,"farenheit")

main()

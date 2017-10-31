#File: Convert celsius to farenheit
#
def main():
    print("This is a program to cenvert farenheit temp to celsius temp")
    farenheit = eval(input("What is the temparature in farenheit?: "))
    celsius = (farenheit-32)/(9/5)
    print("The temperature is,",celsius,"celsius")

main()

# Name: Tan Tze Guang
# Class: 13S28
# Date: 7 March 2013
# This program takes 2 input values and shows how they change over time.

def main():
    print("This program illustrates 2 chaotic functions")
    first,second = eval(input("Input 2 values between 0 and 1 (a,b): "))

    print("")
    print("%s \t %0.000006f \t %0.000006f" % ("index",first,second))
    print("---------------------------------")
    
    for i in range(10):
        first = 3.9 * first * (1 - first)
        second = 3.9 * second * (1 - second)
        i = i + 1

        print("%d \t %0.000006f \t %0.000006f" % (i,first,second))

main()

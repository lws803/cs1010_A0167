# Name: Tan Tze Guang
# Class: 13S28
# Date: 7 March 2013
# This program takes 2 chaos values. printing them on an output file.

def main():
    outfileName = input("Enter the file which you want to save this into: ")
    outfile = open(outfileName,"w")    

    print("This program illustrates 2 chaotic functions")
    first,second = eval(input("Input 2 values between 0 and 1 (a,b): "))

    print("")
    print("%s \t %0.000006f \t %0.000006f" % ("index",first,second))
    print("%s \t %0.000006f \t %0.000006f" % ("index",first,second),file = outfile)
    print("---------------------------------")
    print("---------------------------------",file = outfile)
    
    for i in range(10):
        first = 3.9 * first * (1 - first)
        second = 3.9 * second * (1 - second)
        i = i + 1

        print("%d \t %0.000006f \t %0.000006f" % (i,first,second))
        print("%d \t %0.000006f \t %0.000006f" % (i,first,second),file = outfile)

    print("")
    print("The output has been saved to:",outfileName)

    outfile.close()
    
main()

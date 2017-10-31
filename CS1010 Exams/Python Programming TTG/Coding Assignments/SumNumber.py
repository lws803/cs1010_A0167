# Sum of first n natural numbers

def main():
    print("This is a program to sum up the first 'n' natural numbers")
    n = eval(input("Enter the value of n: "))

    total = (n*(n+1))/2

    print("Hence the sum of the numbers are: %d" % total)

main()

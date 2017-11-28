def sumN(n):
    return (n*(n+1))/2

def sumNCubes(n):
    n = n**3
    return (n*(n+1))/2

def main():
    print("This program prints the sum of the first \'n\' natural numbers")
    print("Also print the sum of the cube of the first \'n\' natural numbers")

    number = eval(input("Input a value of n: "))

    n = sumN(number)
    nCube = sumNCubes(number)

    print("The sum of \'n\' numbers is: {0}".format(n))
    print("The sum of the cubes of \'n\' numbers is : {0}".format(nCube))

main()

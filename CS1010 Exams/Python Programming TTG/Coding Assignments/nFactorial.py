def main():
    n = eval(input("Input a value of n: "))
    n_factorial = 1

    while n > 0:
        n_factorial = n_factorial * n
        n = n - 1

    print("The factorial of n is: ",n_factorial)

main()

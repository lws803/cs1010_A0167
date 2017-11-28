def prime(number):
    flag = 0
    for i in range(2,number):
        if number % i==0:
            return False
        else:
            continue
    return True

print(prime(27449))

def isPrime():
    number = eval(input("Enter"))
    primeCount = 0
    count = 2
    while primeCount != number:
        validPrime = prime(count)
        count += 1
        if validPrime:
            primeCount += 1
            print(count-1)
    
isPrime()

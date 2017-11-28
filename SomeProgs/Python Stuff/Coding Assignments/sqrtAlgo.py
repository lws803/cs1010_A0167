# Computing square roots

def main():
    print("This program finds the closest estimate to the actual square root of a number")
    x = eval(input("Input the number that you want to square root: "))
    estimate = x/2
    copyE = estimate/2

    while estimate != copyE:
        copyE = estimate
        estimate = (estimate +(x/estimate))/2
        print(estimate)

    print("The value of the square root is",estimate)
        
main()

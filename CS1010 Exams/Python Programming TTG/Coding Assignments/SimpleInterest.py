def greet():
    print("******************************************************************")
    print("Welcome to the Personal Loan Program")
    print()
    print("This program will determine the interest, total amount,")
    print("and monthly payment of your loan.")
    print()
    print("Please follow the instructions carefully")
    print("******************************************************************")

def check_loan(principal):
    if principal <= 20000 and principal >= 1000:
        return principal
    else:
        print("Error! Loan is out of range!")

def check_interest(interest):
    if interest > 0 and interest <= 0.187:
        return interest
    else:
        print("Error! Interest is out of range!")

def check_term(time):
    if time > 0 and time < 5:
        return time
    else:
        print("Error! Term is out of range!")

def main():
    greet()
    
    principal = 0
    interest = 0
    term = 0
    
    while principal == 0:
        principal = eval(input("Input the principal amount: "))
        principal = check_loan(principal)

    while interest == 0:
        interest = eval(input("Input the interest: "))
        interest = interest/100
        check_interest(interest)

    while term == 0:
        term = eval(input("Input the term: "))
        check_term(term)

main()
    

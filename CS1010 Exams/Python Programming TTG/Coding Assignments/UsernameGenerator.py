# Name: Tan Tze Guang
# Class: 13S28
# Date: 4 March 2013
# File: UsernameGenerator.py
# This is a program to read a person's name and print a username for them

def main():
    print("This is a program to read a person's name and prints a username for them")

    print("First name: ")
    first_name = input() # Asks for first name of the user
    print("Last name: ")
    last_name = input() # Asks for the last name of the user
    
    username = first_name[0] + last_name[0:7]
    # Assigns 1st character of first name and 7 characters of last name to username
    
    print("Your assigned username is:",username.lower())

main()

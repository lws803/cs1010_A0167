# Name: Tan Tze Guang
# Class: 13S28
# Date: 14 March 2013
# This program reads the file and computes the sum of squares of numbers from the file.

def squareEach(nums): # Function to square numbers in a list
    new_list = [] # Creates a temporary list to store new values to be returned
    
    for number in nums:
        squared_number = number * number
        new_list.append(squared_number)

    return new_list

def sumList(nums): # Function to sum numbers in a list
    sums = 0

    for number in nums:
        sums = sums + number

    return sums

def toNumbers(strList): # Function to convert 'str' to 'int' in list
    new_list = [] # Creates a temporary list to store new values to be returned
    
    for string in strList:
        new_number = int(string)
        new_list.append(new_number)

    return new_list

def main():
    infile = open("ListOfNumbers.txt","r")
    extra_list = []
    
    print("This program reads a the file \"ListOfNumbers\"")
    print("and computes the sum of the squares of the numbers in the file.")

    outfileName = input("Input the name of the output file: ")
    outfile = open(outfileName,"w")

    print("Process:",file = outfile)

    temp_list = infile.readlines() # Recieves data from file
    print(temp_list, file = outfile)

    extra_list = toNumbers(temp_list) # Converts data to 'int' type
    print(extra_list, file = outfile)

    temp_list = squareEach(extra_list) # Squares all integers in list
    print(temp_list, file = outfile)

    extra_list = sumList(temp_list) # Sums up all squares
    print(extra_list, file = outfile)
    
    print("",file = outfile)
    print("The sum of squares are:",extra_list)
    print("The sum of squares are:",extra_list, file = outfile)
    print("The values are saved onto",outfileName)
    
    infile.close()
    outfile.close()

main()
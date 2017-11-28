# Name: Tan Tze Guang
# Class: 13S28
# Date: 15 April 2013
# This  program performs a linear search on a file for a value

def check_elements(data): # checks whether the list is 100 elements or more
    if len(data) < 100:
        print("List need to be at least 100 elements long.")
        return True
    else:
        return False

def linearSearch(data,inputSearch):
    max_num_element = len(data) - 1
    element_found = False # keeps loop on until value found or reach end of list
    index = 0

    while not element_found and index <= max_num_element:
        if data[index] == inputSearch: # found number, break from loop
            element_found = True
        else: # if value not found in current element, go to the next number
            index = index + 1

    if element_found == True: # found the number
        print(data[index],"found at the",index,"space")
    else:
        print("Value not found",inputSearch)

def main():
    print("This program searches for a value within a file.")
    print("File must contain at least 100 values.")
    invalid_elements = True
    while invalid_elements:
        infileName = input("Enter file name: ")
        infile = open(infileName,"r")

        data = infile.readlines()
        data = data[0]
        data = data.split(",") # creates a list of str type numbers
        invalid_elements = check_elements(data)

    inputSearch = input("Enter a value to search: ") # ask for str type number
    linearSearch(data,inputSearch)

main()

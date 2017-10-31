# Name: Tan Tze Guang
# Class: 13S28
# Date: 15 April 2013
# This  program performs a binary search on a file for a value

def check_elements(data): # checks whether the list is 100 elements or more
    if len(data) < 100:
        print("List need to be at least 100 elements long.")
        return True
    else:
        return False
    
def binarySearch(newData,inputSearch): # performs a binary search
    element_found = False # keeps the loop on until number found or end of list
    low_element = 0 # first element in the list
    high_element = len(newData) - 1 # last element in the list
    
    while not element_found and low_element <= high_element:
        index = (low_element + high_element) // 2
        if newData[index] == inputSearch:
            element_found = True # found number, break out of loop
        else:
            if inputSearch < newData[index]:
                high_element = index - 1 # cannot find number, narrows search by half
            else:
                low_element = index + 1
                
    if element_found == True:
        print(newData[index],"is found at position",index + 1)
    else:
        print("Value not found,",inputSearch)
        
def main():
    print("This program performs a binary search on a file for a value")
    print("The file must contain at least 100 values.")
    invalid_elements = True
    while invalid_elements:
        infileName = input("Enter file name: ")
        infile = open(infileName,'r')
        newData = [] # a list to store all int type numbers

        data = infile.readlines()
        data = data[0]
        data = data.split(",") # a list full of str type numbers
        invalid_elements = check_elements(data)
    
    for i in data: # converts all data in list into int type,store in a new list
        number = int(i)
        newData.append(number)
    newData.sort()
    
    inputSearch = eval(input("Enter a value to search: "))
    binarySearch(newData,inputSearch)

main()

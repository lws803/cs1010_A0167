def squareEach(List):
    for item in range(len(List)): # loops through the length of the list
        List[item] = List[item]**2 # squares each item of the list

    return List

def sumList(nums):
    sums = 0
    for item in range(len(nums)): # loops through the length of the list
        sums += nums[item] # adds each item to sums

    return sums

def toNumbers(strList):
    for item in range(len(strList)): # loops through the length of the list
        strList[item] = int(strList[item]) # changes each item of the list to int

    return strList

def main(): 
    infile = open("numberList.txt","r") # opens the file to be accessed.
                                        # take 'infile' as a reference point
    outfileName = input("The target folder for out put: ")
    outfile = open(outfileName,"w") # opens the file to be accessed, creates if needed

    readList = infile.readlines() # reads the data from the infile and places it in  readList

    toNumbers(readList) # calls toNumbers func
    print(readList)
    
    squareEach(readList) # calls squareEach func
    print(readList)
    
    sums = sumList(readList) # calls sumList func, places return to sums

    print("The sum of the numbers in the list is:",sums)
    print(sums, file = outfile) # transfer the final sum to the output file.

main() # the program starts here

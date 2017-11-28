# Name: Tan Tze Guang
# Class: 13S28
# Date: 26 March 2013
# This program finds the mean, median and mode of a list of numbers

def mean(List):
    sums = 0 # A temporary storage for sum of numbers in list
    for items in range(len(List)): # Sums all numbers in the list
        sums = sums + items

    mean_num = sums/len(List) # Finds the 'Mean' here
    
    return mean_num

def median(List):
    List.sort() # Changes the list into numerical order
    count = len(List)
    check = count % 2 # Checks whether the nuber is odd or even

    if check == 0: # Even number
        median_num = (List[(len(List))//2] + List[(len(List)//2)+1])/2
        return median_num

    if check == 1: # Odd number
        median_num = List[(len(List)//2)]
        return median_num

def mode(List): # Currently only can find 1 mode
                # Multiple modes will cause the smaller mode to be removed
    List.sort()
    frequency = [] # Creates a list to store values of frequency of value
    count = len(List) - 1

    for items in List:
        freq = 0 # Ensures that freq is reset after every loop
        freq = List.count(items)
        frequency.append(freq)

    print("This is the current List:",List)
    print("Frequency of numbers is:",frequency)

    while count > 0: # This is to remove all non-mode numbers
        if frequency[0] == frequency[1]:
            List.pop(0)
            frequency.pop(0)

        elif frequency[0] > frequency[1]:
            List.pop(1)
            frequency.pop(1)

        elif frequency[0] < frequency[1]:
            List.pop(0)
            frequency.pop(0)

        count = count - 1
        
    return List[0]

def main():
    print("This program finds the mean,median and mode of a list of numbers.")
    print("Currently, the program is only able to find 1 mode.")
    print("In the case of multiple modes, the smaller mode will be removed.")
    print("")
    
    numbers = [8,6,7,9,9,6,4,4,6,8,9,9,9,8,7,7,6]
    print("The list has",len(numbers),"numbers")
    print()
    mean_number = mean(numbers)
    print("The mean of this list of numbers is",mean_number)
    print()

    median_number = median(numbers)
    print("The median of this list of numbers is",median_number)
    print()
    
    mode_number = mode(numbers)
    print("The mode of this list of numbers is",mode_number)

main()

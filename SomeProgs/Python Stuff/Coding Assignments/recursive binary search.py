# Name: Tan Tze Guang
# Class: 13S28
# Date: 18 April 2013
# Recursive binary search

# Binary Search Algorithm
# INPUT:
#   data is an array of integers SORTED in ASCENDING order
#   toFind is the integer to search for,
#   start is the minimum array index,
#   end is the maximum array index
# OUTPUT:
#   position of the integer toFind within array data, -1 if not found

def recursive_binary_search(data,toFind,start,end):
    mid = (start + end) // 2 # integer division
    if start > end:
        return -1 # not found
    elif data[mid] == toFind: # if found
        return mid
    elif data[mid] > toFind: # data greater than lower half, search lower half
        return recursive_binary_search(data,toFind,start,mid-1)
    else: # data smaller than lower half, search upper half
        return recursive_binary_search(data,toFind,mid+1,end)

def main():
    infileName = "newscore.txt"
    infile = open(infileName,'r')
    temp = infile.readlines()
    temp = temp[0]
    temp = temp.split(",")
    array = []
    for i in temp:
        item = int(i)
        array.append(item)
    data = array
    print(data)
    toFind = eval(input("Enter search: "))
    start = 0
    end = len(data)
    display = recursive_binary_search(data,toFind,start,end)
    print(display)

    if display == -1:
        print("value not found.")
    else:
        print(toFind,"is found at position", display)

main()

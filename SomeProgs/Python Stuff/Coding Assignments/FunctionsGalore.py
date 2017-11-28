# Name: Tan Tze Guang
# Class: 13S28
# Date: 14 March 2013
# A lot of functions a)Square   b)Sum   c)Convert str to int

def squareEach(nums):
    new_list = []
    
    for number in nums:
        squared_number = number * number
        new_list.append(squared_number)

    return new_list

def sumList(nums):
    sums = 0

    for number in nums:
        sums = sums + number

    return sums

def toNumbers(strList):
    new_list = []
    
    for string in strList:
        new_number = int(string)
        new_list.append(new_number)

    return new_list

def main():
    numberList = [1,2,3,4,5]
    stringList = ['1','2','3','4','5','6']
    
    print("Current int list:",numberList)
    print("Current str list:",stringList)
    print()
    
    new_numbers = squareEach(numberList)
    print("The square of the numbers of the list:",new_numbers)

    sum_numbers = sumList(numberList)
    print("The sum of the numbers of the list:",sum_numbers)

    convert_numbers = toNumbers(stringList)
    print("The new list is:",convert_numbers)
    
main()

# This program looks up the [key] from a value and dictionary input.

def reverse_lookup(dic,value):
    for key in dic: # From 1st to last element in the dictionary
        # scan each value of each key and compare with input value
        if dic[key] == value:
            return key # if found, return key
    raise ValueError # else return not found.

def dic(word):
    dic = {}
    for key in word:
        dic[key] = dic.get(key,0) + 1
    return dic

def main():
    userInput = input("Enter something: ")
    user = dic(userInput)
    value = eval(input("Enter a number: "))
    key = reverse_lookup(user,value)
    print(key)
    
main()
